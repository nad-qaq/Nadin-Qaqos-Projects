Assignment 5 - evaluating infix equation program
======================================================================
This program takes an arithmetic equation from the user in infix 
form and evaluates the value using polymorphism and trees. 


In Folder
==================
main.cpp
token.cpp
token.h
ch12-1.cpp
makefile
README.txt


How to Run:
======================================================================
1. Type "make" into the terminal while in the correct folder to 
compile program.
2. Type "prog5" to run the program.
3. Enter an arithmetic equation to be solved.		
4. Enter "make clean" to remove files created from compiling.

Example output:

"""
Enter an expression: 6-4
going through this token: 4
going through this token: -
going through this token: 6
Result: 2
"""


Files:
======================================================================
* main.cpp - this has two functions. One that will convert to postfix
and another that will evaluate the result. Both of the funcions are
used in the main method. 
* token.cpp - given. 
* ch12-1.cpp - given
* token.h - this has all of the functions that are in the token.cpp


Bugtesting
======================================================================
I have run this and it works if you don't use the parentheses. I 
couldn't figure how to fix it or where it was going wrong. I think 
it was my stack. Because it was looking at in reverse. But again, 
I'm not sure if that was the issue or not. 



Prof Notes
======================================================================
You are correct about the reversal of the stack. That would help rid the program of the segmentation fault.

After that, the result is still incorrect though. This is because when you call BinaryNode, the left and right parameters are out of order. If you switch their order, everything works as intended.

Otherwise, great work!