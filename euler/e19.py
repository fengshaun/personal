#days = ['sun', 'mon', 'tue', 'wed', 'thu', 'fri', 'sat']
#months = ['jan', 'feb', 'mar', 'apr', 'may', 'jun', 'jul', 'aug', 'sep', 'oct', 'nov', 'dec']
day_of_month = [1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6] # for 1900
num_sundays = 0 # for 1900
# jan 1 1901 is mon
#day_tracker = 1

def is_leap_year(year):
    # ignore centuries for now
    if not year % 100:
        if not year % 400:
            return True
        else:
            return False
    else:
        if not year % 4:
            return True
        else:
            return False

for year in range(1901, 2001):
    if is_leap_year(year):
        for month in range(2):
            day_of_month[month] += 1
        for month in range(2, 12):
            day_of_month[month] += 2
    elif is_leap_year(year - 1):
        for month in range(2):
            day_of_month[month] += 2
        for month in range(2, 12):
            day_of_month[month] += 1
    else:
        # update day_of_month
        for month in range(12):
            # days shift in each month by 1 day
            # in normal years
            day_of_month[month] += 1

    # keep it under 6
    for month in range(12):
        if day_of_month[month] > 6:
            day_of_month[month] -= 7

    # check the number of sundays
    for month in range(12):
        if day_of_month[month] == 0:
            # got a sunday
            num_sundays += 1

def solve():
    return num_sundays

if __name__ == '__main__':
    print solve()

# emandres from projecteuler.net:
'''
import datetime
count = 0
for y in range(1901,2001):
    for m in range(1,13):
        if datetime.datetime(y,m,1).weekday() == 6:
            count += 1
print count
'''
