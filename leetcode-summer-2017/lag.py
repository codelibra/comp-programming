
# coding: utf-8

# In[133]:

import os


# In[134]:

os.system('cd /Users/shiv/.bin/comp-programming/leetcode-summer-2017/;git pull;')


# In[135]:

import codecs
f = codecs.open('/Users/shiv/.bin/comp-programming/leetcode-summer-2017/Leetcode.txt', encoding='utf-8')
all_questions = list()
index = 0
for line in f:
    index = index + 1
    if index<=10:
        continue
    line = line.split(' ')
    all_questions.append(line)


# In[136]:

a_easy_lag =0
a_medium_lag =0
a_hard_lag =0
a_algo_lag =0
s_easy_lag =0
s_medium_lag =0
s_hard_lag =0
s_algo_lag=0

a_easy_done = 0
a_medium_done = 0
a_hard_done = 0
a_algo_done = 0
s_easy_done = 0
s_medium_done = 0
s_hard_done = 0
s_algo_done = 0

easy_per_day = 2
medium_per_day = 4
hard_per_day = 2
algo_per_week = 2

# In[137]:

for question in all_questions:
    if "Easy" in question:
        if question[1]==u'\u2714':
            s_easy_done += 1

        if question[2]==u'\u2714':
            a_easy_done += 1

    if "Medium" in question:
        if question[1]==u'\u2714':
            s_medium_done += 1

        if question[2]==u'\u2714':
            a_medium_done += 1

    if "Hard" in question:
        if question[1]==u'\u2714':
            s_hard_done += 1

        if question[2]==u'\u2714':
            a_hard_done += 1

    if "Algo" in question:
        if question[1]==u'\u2714':
            s_algo_done += 1

        if question[2]==u'\u2714':
            a_algo_done += 1



# In[138]:

import datetime
from datetime import date

def days_between():
    start_date = datetime.date(2017,5,22)
    today = date.today()
    return abs((today - start_date).days)


# In[139]:

def calculate_lag():
    days = days_between()
    easy = easy_per_day * days
    medium = medium_per_day *days
    hard = hard_per_day *days
    algo = algo_per_week * (days/7)

    a_easy_lag = a_easy_done - easy
    a_medium_lag = a_medium_done - medium
    a_hard_lag = a_hard_done - hard
    a_algo_lag = a_algo_done - algo

    s_easy_lag = s_easy_done - easy
    s_medium_lag = s_medium_done - medium
    s_hard_lag = s_hard_done - hard
    s_algo_lag = s_algo_done - algo

    line = "Shiv Easy Lag     " + str(s_easy_lag)+ "\n"
    line += "Shiv Medium Lag   " + str(s_medium_lag) + "\n"
    line += "Shiv Hard Lag     " + str(s_hard_lag)+ "\n"
    line += "Shiv Algo Lag     " + str(s_algo_lag)+ "\n"

    line += "Akshay Easy Lag   " + str(a_easy_lag)+ "\n"
    line += "Akshay Medium Lag " + str(a_medium_lag) + "\n"
    line += "Akshay Hard Lag   " + str(a_hard_lag)+ "\n"
    line += "Akshay Hard Lag   " + str(a_algo_lag)+ "\n"
    return line




# In[140]:

with open('/Users/shiv/.bin/comp-programming/leetcode-summer-2017/Leetcode.txt', 'r') as fin:
    data = fin.read().splitlines(True)
with open('/Users/shiv/.bin/comp-programming/leetcode-summer-2017/Leetcode.txt', 'w') as fout:
    fout.writelines(data[6:])


# In[141]:

line = calculate_lag()
with open('/Users/shiv/.bin/comp-programming/leetcode-summer-2017/Leetcode.txt', 'r') as f:
    content = f.read()

with open('/Users/shiv/.bin/comp-programming/leetcode-summer-2017/Leetcode.txt', 'w') as f:
    f.write(line.rstrip('\r\n') + '\n' + content)


# In[143]:

os.system('cd /Users/shiv/.bin/comp-programming/leetcode-summer-2017/;git add Leetcode.txt;git commit -m "Current Status";git push -f origin master')
