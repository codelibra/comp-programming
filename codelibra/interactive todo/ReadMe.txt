todo list

features which needed to be supported?
1.making todo
2.writing notes

so what all should it support?
one of the most basic things is that it should be running in the background and should know what all i am typing or doing if possible.

every morning or the start of day we must say "start of day" to the program.
ex: todo -sod

everyday at the end of the day we must tell that it is the "end of day".
the program should then tell the complete summary of things via email.
ex: todo -eod
This will give a list of all the tasks which are blocked state, which can be changed by the user

always the right questions must be asked, but the reply will not be mandatory!
ex: what should i tag the note with?

always there should be a way to reply easily, using a shortcut or typing minimal. this will propmt the person to answer, and solve the purpose.
ex: what should i tag the note with?
ans:
probables:
shotcut   tag

Shift+a | study
Shift+b | codex
Shift+c | personnel

whenever a user enters any particular word which has a spelling mistake then the user should be notified and y/n must be asked for the most probable match.

so let's begina typical day:-
>todo -sod
>>Hi shivendra!! you have a nice day ahead of you :) [ this message must change on a daily basis]


task/subtask has states:-
1. Not started
2. active
3. Done
4. Blocked
5. Unknown

Restrictions:-
1. one can have one task active at a time
2. we can switch between tasks, making the current task to become blocked
3. when a task is added then it is by default "not started"
4. once we add subtasks to a task, then we need to mark the subtasks as done. the task overall cannot be marked as done.
5. in order to add a task the title and the time are the only mandatory parameters
6. priority of tasks are within their categories ie., the work category will have tasks with priority one and same with home category
7. priority will be unique within a category
8. a taskmay recur but not a subtask

Adding a new task:-
it should be extremely easy to add new task and to add the related meta data with the task.
>todo -add_task --title "title for task1"
this prints the unique taskid of the task

what is the category? [--category] home, work, personnel, emergency
what is the priority? [--priority] 1,2,3,4,5,next task,now,last,-1,-2,-3
when do u want to be reminded about the task? [--time] should support variation form the current date and time(+30,+15,eod.)
is it a recurring task? [--recur] daily,weekly,monthly,yearly
what is the tag? [--tag] zookeeper, java, javascript, testing
description? [--desc]
please break the task into subtasks, add subtasks? [--sub_tasks]
what all will you learn while doing this task? [--learn]

>todo -add_task --title "title for task1" --time +30 --skip_que
this will not ask any questions, just add the task to the list with whatever defaults.

Listing all the tasks:-
>todo -l
>todo -l -expand (this will expand the tasks into their subtasks)
>todo -l --status done


Category1

TaskId Priority Title description time-left tag status
------------------------------------------------------


which task am i working on currently?
figure out a way to show the same.
may be show using the terminal header!!

how to start working on a new task?
there are multiple ways to start
>todo -start_task --category "work" --priority 1
>todo -start_task --category "work" --priority 1 --sub_task 3
>todo -start_task --taskId 45
>todo -start_task --taskId 47.2
>todo -start_task --title "AE#1234"


how to switch between tasks?
switch-
from one task to another-> this means the current task will be marked as blocked, and new task will be the active task
from one subtask to another -> this means the current subtask will be set as blocked and the new subtask will be active
from one subtask to another task -> current  task and subtask will be marked as blocked and the new task will be active
form one subtask to another task's subtask-> similar

>todo -start_task also switch to the new task whichever is started.


how to edit a task?
when we just add a task to the list without any info, we can come back to the same and edit the meta data whenever required.

>todo -edit_task
all the similar questions will be asked and the data will be overriden if any is already present.

can we also add subtasks to a particular task?
>todo -edit_task --add_subtask --title "new subtask" -t +20

can i change the status of a task or a subtask?
>todo -edit_task --status "new status"
if currently i was working on a task then this will change the status of the task.
if currently i was working on a subtask then the status of the task and subtask will be updated.

>todo done!!
this will change the status of the current task or subtask to done.

how to mark a task or a subtask as done?
switch to the task
>todo done!!
this will switch to the highest priority task in the same category.



lets' now talk about notes!!!!
what is a note??
It is very important to keep notes of anything which we are learning.
It is just to read something on internet and then make notes about it in one's own words.
Just the topic name and the notes.


Requirements:-
1.Since we are working on some task whenever we are making notes as well,
the notes will be tagged as the tag's of the current task so that there is no need to tag again.
2.We should be able to search in our notes anything very easily, this will allow people to write notes.
3.we must allow quick add to the end of note. ex:- link, some text , some file,code etc..
4.We can also get all the todo's which were worked on while the task was done which can help
5.There must be some kind of text editor (vim) opened when a particular note is being made, also when it is getting edited.

how is a note related to todo?
when i am working on a todo, all the notes which i take are related.
when i switch between tasks and add notes, all those tasks are related to that note.

how will i add a new note?
>todo -add_note --title "title"
this will open a vim editor where i can type in all the details which are to be noted.
this will also print the note id at the completion of the note taking.

>todo -edit_note --noteId 12
this will open the note with noteid 12, now that can be edited and resaved.

>todo -quick_note
this open the last opened note which can now be edited

>todo -quick_note --noteId 12 --data "some data to be added to the end of the file"
this will quickly add the data to any noteId at the end of file

>todo -note -l

noteId  some-data  last-updated-time  related-todo  tags
--------------------------------------------------------

similar to todo we can add multiple tags and categories to a particular note.
this will help in organising the notes and searching.

>todo -search_note
should be the best feature of the app!!
the note must be allowed to be searched using anything [tags,text,time,todo,category]


Other important features:-
