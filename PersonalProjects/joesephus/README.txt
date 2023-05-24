Assignment 4 
======================================================================
This implements a method to solve the Josephus problem using namespaces, 
exceptions, and the STL. 


qaqos4 Folder
==================
main.cpp
exception.h
josephus.h
makefile
README.txt


How to Run:
======================================================================
1. Type "make" into the terminal while in the correct folder to 
compile program.
2. Type "prog4" to run the program.
3. Follow the prompts and you will get who the last person standin is.  		
4. Enter "make clean" to remove files created from compiling.

Example output:

"""
How many people are in the circle?  6
Which person would you like to start at? 3
1 2 3 4 5 6 
----------------------
1 2 3 4 6 
----------------------
2 3 4 6 
----------------------
2 4 6 
----------------------
2 4 
----------------------
2 
----------------------
The last person standing is: 2
"""


Files:
======================================================================
* main.cpp - this is where all of the functions in exception.h and 
josephus.h get used. 
Namespace is also used in this file.  
* exception.h - this has one exceptions in it. The exception prints out
and error when the user picks a number equal to or less than 0 for the
number of people in the circle. 
* josephus.h - this file is where everything is happening. It has a 
constructor that really only checks to see if you have enough people 
in the circle. It has a kill method that finds the person who is 
supposed to get killed and then kills.  


Bug Testing
======================================================================
I have run this a few times and there are no errors. I didn't count starting 
from the person. For example in the sample output above we start at 
3 but the person killed first is 5. So I skipped one person and killed
the next one in line. And then the next to get killed is 1... and so 
on with that kind of pattern. 