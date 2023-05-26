**************************************************************************************************************************
	Author: Kevin Ton,
	Project: File-Parser
	Filename: Parser.cpp
**************************************************************************************************************************

			Please use cssc0846 for account identifer to be used for testing

**************************************************************************************************************************
LIST OF FILES:

Code Repository:
main.cpp
threading.h
threading.cpp

File Repository:
Makefile
README.txt
QUOTE.txt

**************************************************************************************************************************
COMPILE INSTRUCTIONS:
In directory, type "make"
**************************************************************************************************************************
OPERATION INSTRUCTIONS:
	~/a1 make clean			To clean any leftover files
	~/a1 make			To create an executable
	~/a1 bots			Run executable
	~/a1 vim QUOTE.txt		To check file being written to

List/description of novel/significant design decisions:

	- Formatting and outputting to terminal and output file
	- Read which PID is currently active
	- Have each thread wait for the thread next to it(even/odd) to ensure each thread has enough runtime
**************************************************************************************************************************
List/description of any extra features/algorithms/functionality you included which were not 
required:
N/A
**************************************************************************************************************************
LIST/DESCRIPTION OF ALL KNOWN DEFICIENCIES OR BUGS
N/A
**************************************************************************************************************************
LESSONS LEARNED: 
Working with threads
Learn how multithreading and semaphores work
Learn how to effectively allocate enough time for a processor to execute and interact with one another through shared resources
**************************************************************************************************************************
