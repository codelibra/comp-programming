'''
This script is meant to initialize the todo app.
It will take the necessary inputs from the user.
Depending on the inputs from the user it will call necessary module.
'''
import argparse
from todo import TodoAction
from note import NoteAction

def main():
    parser = argparse.ArgumentParser(description='Process arguments')
    parser.add_argument('--todo', '-t', action=TodoAction)
    parser.add_argument('--note', '-n', action=NoteAction)
    args = parser.parse_args()

'''
Initiating the todo app
''' 
if __name__ == '__main__' :
    main()
