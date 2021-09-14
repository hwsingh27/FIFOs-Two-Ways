# PES-Assignment-2
Code for Assignment 2 for PES, ECEN-5813, Fall 2021

@files main.c cbfifo.c test_cbfifo.c llfifo.c test_llfifo.c
@author Harshwardhan Singh
@date September 13th 2021

## LLFIFO
There are five functions that are implemented which are used to enqueue and dequeue the elements to and from the FIFO using linked list.
Two of the functions are used to compute the length and the capacity of the FIFO. The create function is used to create the linked list (number of nodes).
The enqueue function takes the first parameter as the FIFO given in the problem statement and second parameter is the element that is
to be enqueued which cannot be passed as NULL. The function returns the length of the FIFO on success, returns -1 on failure. And it is
considered an error to enqueue the NULL pointer.
The dequeue function takes only one parameter as the FIFO in the problem statement. The function returns the dequeued element from the FIFO
if works fine, it returns -1 on failure and NULL if the FIFO was empty.
The length and capacity functions are used to return the computed number of elements in the FIFO and the capacity of the FIFO respectively
and takes FIFO as the parameter.

## CBFIFO
There are four functions that are implemented which are used to enqueue and dequeue the elements to and from the FIFO using circular buffer.
Two of the functions are used to determine the length and the capacity of the FIFO. There are various arguments passed while calling the 
enqueue and dequeue functions.
The queue "cbuff" of uint8_t data type and 128 bytes of size is declarede globally.
The enqueue function takes the "buf" pointer to the data and "nbyte" is the maximum number of bytes to be enqueued. This function
returns the number of bytes actualy enqueued that can be "0" and returns "-1" in case of an error.
The dequeue function takes the "buf" pointer pointing to the destination for moving the dequeued data and the required number
of bytes to be dequeued. The functions returns the number of bytes copied that can be between "0" and nbytes and returns "-1" in case of
an error.
The length and capacity functions are used to return the maximum number of elements in the FIFO that can be dequeued and maximum number of elements that
can be stored in the FIFO respectively.

## TOOLS
Code Blocks for C programming in Windows 64-bit system is used to accomplish this task. Main file (main.c) calls the test functions (test_llfifo.c and test_cbfifo.c)
and these test files call the production code files (llfifo.c and cbfifo.c) in order to run the complete program. Two header files (llfifo.h and cbfifo.h)
are also included in the project.
