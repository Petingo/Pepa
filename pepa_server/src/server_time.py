from datetime import datetime
import pytz

def get_current_time():
    """
    Get the current time in the format of "YYYY MM DD HH MM SS D" 
    For example: 2023 01 06 23 50 22 5 ('D' is the weekday 0-6, 0 is for Sunday)
    Ref: https://www.programiz.com/python-programming/datetime/strftime
    """
    
    tz_CH = pytz.timezone('Europe/Zurich')
    now = datetime.now(tz_CH)

    return now.strftime("%Y %m %d %-H %-M %-S %w")
    
