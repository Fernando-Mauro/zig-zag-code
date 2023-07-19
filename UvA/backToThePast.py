from datetime import datetime
import calendar

date = datetime(2013,5,29)
print('May 29, 2013 {}'.format(calendar.day_name[date.weekday()]))