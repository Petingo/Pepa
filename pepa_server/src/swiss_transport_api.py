import requests
from typing import List
from pprint import pprint
from datetime import datetime
from bs4 import BeautifulSoup

class SwissTransportAPI:
    def __init__(self, key: str = "57c5dbbbf1fe4d000100001842c323fa9ff44fbba0b9b925f0c052d1", stations_to_monitor: List[str] = []) -> None:
        self.key = key
        self.stations_to_monitor = stations_to_monitor
        self.__headers = {
            "Authorization": key,
            "Content-Type": "application/xml",
        }
        
    def __parse_response(self, response: requests.Response):
        if response.status_code != 200:
            print("Error:", response.status_code)
            return {}
        
        resp_text = str(response.content, 'utf-8', errors='replace') # response.text decodes incorrectly
        soup = BeautifulSoup(resp_text, "xml")
        departure_data = {}     # line -> destination -> [time1, time2, ...]
        destination_data = {}   # destination_id -> destination_text
        for stop_event in soup.find_all("trias:StopEventResult"):
            publish_line_name = stop_event.PublishedLineName.Text.text
            destination_id = stop_event.DestinationStopPointRef.text
            destination_text = stop_event.DestinationText.Text.text
            
            service_departure = stop_event.ServiceDeparture
            if service_departure.find("EstimatedTime") is not None:
                time = service_departure.EstimatedTime.text
            else:
                time = service_departure.TimetabledTime.text
            
            if publish_line_name not in departure_data:
                departure_data[publish_line_name] = {}
            if destination_id not in departure_data[publish_line_name]:
                departure_data[publish_line_name][destination_id] = []
            departure_data[publish_line_name][destination_id].append(time)
            
            destination_data[destination_id] = destination_text
        return departure_data, destination_data


    def get_all_departure_data(self) -> dict:
        all_departure_data = {}
        all_destination_data = {}
        for station in self.stations_to_monitor:
            self.__payload_template_soup.StopEventRequest.Location.LocationRef.StopPointRef.string = station
            self.__payload_template_soup.ServiceRequest.RequestTimestamp.string = datetime.utcnow().isoformat()
            payload = str(self.__payload_template_soup)
            response = requests.post(url=self.__url, headers=self.__headers, data=payload)
            
            departure_data, destination_data = self.__parse_response(response)
            all_departure_data.update(departure_data)
            all_destination_data.update(destination_data)
        
        return all_departure_data, all_destination_data
            
    __url = "https://api.opentransportdata.swiss/trias2020"
    __payload_template = """
        <?xml version="1.0" encoding="UTF-8"?>
        <Trias version="1.1" xmlns="http://www.vdv.de/trias" xmlns:siri="http://www.siri.org.uk/siri" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
            <ServiceRequest>
                <siri:RequestTimestamp></siri:RequestTimestamp>
                <siri:RequestorRef>API-Explorer</siri:RequestorRef>
                <RequestPayload>
                    <StopEventRequest>
                        <Location>
                            <LocationRef>
                                <StopPointRef></StopPointRef>
                            </LocationRef>
                        </Location>
                        <Params>
                            <NumberOfResults>10</NumberOfResults>
                            <StopEventType>departure</StopEventType>
                            <IncludePreviousCalls>false</IncludePreviousCalls>
                            <IncludeOnwardCalls>false</IncludeOnwardCalls>
                            <IncludeRealtimeData>true</IncludeRealtimeData>
                        </Params>
                    </StopEventRequest>
                </RequestPayload>
            </ServiceRequest>
        </Trias>
        """
    __payload_template_soup = BeautifulSoup(__payload_template, "xml")
        

if __name__ == "__main__":
    try:
        from key import key
    except ImportError:
        pass
    
    stations_to_request = ["8592068", "8593838", "8593837", "8595938"]
    api = SwissTransportAPI(key=key, stations_to_monitor=stations_to_request)
    all_departure_data, all_destination_data = api.get_all_departure_data()
    
    pprint(all_departure_data)
    pprint(all_destination_data)
