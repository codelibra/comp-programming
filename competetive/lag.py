



import os



os.system('cd /Users/shiv/.bin/comp-programming/competetive/;git pull;')



import codecs
f = codecs.open('/Users/shiv/.bin/comp-programming/competetive/competitive.todo', encoding='utf-8')
all_questions = list()
index = 0
for line in f:
    line = line.split(' ')
    if len(line)<3:
        continue
    all_questions.append(line)



lag =0
done = 0



for question in all_questions:
    if u'\u2714' in question:
        done += 1

import datetime
from datetime import date

def days_between():
    start_date = datetime.date(2017,5,22)
    today = date.today()
    return abs((today - start_date).days)



def calculate_lag():
    days = days_between()
    lag = done - 2 * days

    line = "Shiv Competetive Lag     " + str(lag)+ "\n"
    return line




with open('/Users/shiv/.bin/comp-programming/competetive/competitive.todo', 'r') as fin:
    data = fin.read().splitlines(True)
with open('/Users/shiv/.bin/comp-programming/competetive/competitive.todo', 'w') as fout:
    fout.writelines(data[1:])



line = calculate_lag()

with open('/Users/shiv/.bin/comp-programming/competetive/competitive.todo', 'r') as f:
    content = f.read()

with open('/Users/shiv/.bin/comp-programming/competetive/competitive.todo', 'w') as f:
    f.write(line.rstrip('\r\n') + '\n' + content)

os.system('cd /Users/shiv/.bin/comp-programming/competetive/;git add competitive.todo;git commit -m "Current Status";git push -f origin master')
