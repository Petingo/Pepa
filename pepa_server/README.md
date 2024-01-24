# Pepa Server
The backend server for pepa.

## Commands to run the server
``` bash
. .venv/bin/activate
flask --app pepa_server run
```

## Bus departure/arrival time
The real-time data for the bus departure/arrival time is requested through 
the [TRIAS 2020 API](https://opentransportdata.swiss/en/cookbook/departurearrival-display/) provided by [Open data platform mobility Switzerland](https://opentransportdata.swiss/en/).

The interface/function we have here is designed to monitor a list of bus stops. The usage of the API is as follows:
```python
stations_to_request = ["8592068", "8593838", "8593837", "8595938"]
api = SwissTransportAPI(key=key, stations_to_monitor=stations_to_request)
all_departure_data, all_destination_data = api.get_all_departure_data()
```
The API key can be requested without charge after registering an account in [Open data platform mobility Switzerland](https://opentransportdata.swiss/en/). 
If the key is not provided, a test key will be used (not sure if there is any limitation).

The station ID can be found in [TRIAS 2020 API Documentation](https://opentransportdata.swiss/en/cookbook/departurearrival-display/) using API Explorer with `Location Information Request` template.
Here's the four bus stops we are monitoring:
- Lausanne, Maladière：`8592068`
- Lausanne, Maladière-Lac：`8593838`
- Lausanne, Maladière-Figuiers：`8593837`
- Lausanne, Vidy-Port：`8595938`

If the request is executed successfully, two dictionaries will be returned: `all_departure_data` and `all_destination_data`.

### all_departure_data
- Bus line number → Destination ID → List of departure time 
```
{'1': {'8591994': ['2024-01-24T22:15:00Z',
                   '2024-01-24T22:30:00Z',
                   '2024-01-24T22:45:00Z',
                   '2024-01-24T23:00:00Z',
                   '2024-01-24T23:15:00Z']},
 '2': {'8579254': ['2024-01-24T23:18:00Z'],
       '8592030': ['2024-01-24T22:03:00Z',
                   '2024-01-24T22:18:00Z',
                   '2024-01-24T22:33:00Z',
                   '2024-01-24T22:48:00Z',
                   '2024-01-24T23:03:00Z',
                   '2024-01-25T04:10:00Z',
                   '2024-01-25T04:25:00Z',
                   '2024-01-25T04:40:00Z',
                   '2024-01-25T04:55:00Z']},
 '24': {'8501210': ['2024-01-24T22:26:00Z',
                    '2024-01-24T22:56:00Z',
                    '2024-01-24T23:10:00Z',
                    '2024-01-24T23:25:00Z',
                    '2024-01-25T05:37:00Z'],
        '8595936': ['2024-01-24T22:21:00Z',
                    '2024-01-24T22:51:00Z',
                    '2024-01-24T23:11:00Z',
                    '2024-01-25T05:22:00Z',
                    '2024-01-25T05:31:00Z']},
 '25': {'8588445': ['2024-01-24T22:05:00Z',
                    '2024-01-24T22:19:00Z',
                    '2024-01-24T22:34:00Z',
                    '2024-01-24T22:49:00Z',
                    '2024-01-24T23:02:00Z'],
        '8593869': ['2024-01-24T22:06:00Z',
                    '2024-01-24T22:18:00Z',
                    '2024-01-24T22:33:00Z',
                    '2024-01-24T22:47:00Z',
                    '2024-01-24T23:02:00Z']},
 '6': {'8592101': ['2024-01-24T22:07:00Z',
                   '2024-01-24T22:22:00Z',
                   '2024-01-24T22:37:00Z',
                   '2024-01-24T22:52:00Z',
                   '2024-01-24T23:03:00Z']}}
```
### all_destination_data
- Destination ID → Destination name
```
{'8501210': 'Lausanne, Bourdonnette',
 '8579254': 'Lausanne, St-François',
 '8588445': 'Pully, gare',
 '8591994': 'Lausanne, Blécherette',
 '8592030': 'Lausanne, Désert',
 '8592101': 'Lausanne, Praz-Séchaud',
 '8593869': 'Chavannes-R., Glycines',
 '8595936': 'Lausanne, Tour Haldimand-Lac'}
```
