from datetime import datetime
import pytz

def get_current_time():
    tz_CH = pytz.timezone('Europe/Zurich')
    now = datetime.now(tz_CH)

    # 2023 01 06 23 50 22 5 (weekday 0-6)
    # https://www.programiz.com/python-programming/datetime/strftime
    return now.strftime("%Y %m %d %-H %-M %-S %w")
    
