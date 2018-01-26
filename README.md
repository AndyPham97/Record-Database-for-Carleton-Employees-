
###########PURPOSE OF THIS SOFTWARE##############
Purpose of this software is to mainpulate records of all the employees at Carleton

##########DEVELOPER AND DEVELOPMENT DATE############
Developer is Andy Pham and development started at November 18th, 2017

#########HOW THE SOFTWARE IS ORGRANIZED##############
1. The files include:
      The header files and they are linked_list.h and bubble_sort.h
      The c files which are main.c and linked_list.c
      The object files which are bubble_sort.o, main.o, linked_list.o, main_test.o, and main_test_delete_leak.o

2. Not sure if we need to include the tester programs, but they are:
         The 2 make files for creating the 2 test programs, Makefile for one and Makefile_leak for the other
         The created programs that were compiled from the make files are main_test, main_test_delete and main_test_delete_leak

##########INSTRUCTIONS ON HOW TO COMPILE THE PROGRAM#############
1.To compile the main program:
     You type in the following command 'gcc -g main.c linked_list.c bubble_sort.o'
     Then type in './a.out' to execute the program

2. To compile the main_test program:
         You type in 'make' and './main_test' afterwards to execute the program

3. To compule the main_test_delete program:
	    You type in 'make -f Makefile_leak'
	    Before executing the program, you must add the current directory of all your files to compile the software application by 'PATH=$PATH:.;'
	    Now the environment variable PATH knows where all the files necessary for executing the program, you can type in 'main_test_delete' without the './' anymore and this
applies to running other programs

#####ISSUES AND LIMITATIONS########
1. After using the main_test_delete program, it appears to have several memory leaks
2. Adding other utilities like:
     Upgrading the remove duplicates function so it can perform it on an unordered list
     A deleteNodeById function

######INSTRUCTIONS ON HOW TO USE THE SOFTWARE#############
The main program will perform several operations such as inserting a new record at the front of the list, printing out all the records' data in the list, and removing duplicate records in an ordered 
list for example. However, they will be seperated into smaller segments so that it will not perform all the designated operations at once and you will be abe to see it all step by step. Therefore, when you will see 'Hit <cr> to continue' and that means before you can proceed to the next operation executed, you have to press ENTER to proceed. 

