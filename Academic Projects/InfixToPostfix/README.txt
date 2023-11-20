Assignment 1 - infix to postfix program
======================================================================
This program takes an arithmetic equation from the user in infix 
form and converts it to postfix while evaluating the value. 


In Folder
==================
main.cpp
token.cpp
token.h
queueType.h
stackType.h
makefile
README.txt


How to Run:
======================================================================
1. Type "make" into the terminal while in the correct folder to 
compile program.
2. Type "prog1" to run the program.
3. Enter an arithmetic equation to be solved.		
4. Enter "make clean" to remove files created from compiling.

Example output:

"""
enter an expression: (48-23)/4+5
The expression in infix: ( 48 - 23 ) / 4 + 5 
The expression in postfix: 48 23 - 4 / 5 + 
The final result is: 11.25
"""


Files:
======================================================================
* main.cpp - this has two functions. One that will convert to postfix
and another that will evaluate the result. Both of the funcions are
used in the main method. 
* token.cpp - given 
* token.h - this has all of the functions that are in the token.cpp
* queueType.h - given
* stackType.h - given


Bugtesting
======================================================================
I have run this a few times and it didn't have any errors. 