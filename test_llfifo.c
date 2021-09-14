/**
 * @file test_llfifo.c
 * @brief test function for llfifo has been implemented to test several cases for
 * the efficient working of the llfifo.c
 * @author Harshwardhan Singh
 * @date September 13th 2021
 * @tools Code Blocks 20.03
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "LLFIFO.h"

/**
 * @brief function for the test cases, several enqueue and
 * dequeue functions have been performed in addition to the
 * length and capacity functions to check various test cases.
 * Declared one flag that increments when any of the test cases
 * is passed. In order to pass all the test cases, the value of
 * the flag should be equal to the number of test cases passed.
 *
 * @param does not have any parameter
 * @return the functions returns "Test cases passed for ll_fifo" and "1"
 * if all the test cases are passed otherwise returns "Test cases failed for
 * ll_fifo" and "0" if any of the test cases implemented is failed.
 */
int test_llfifo()
{
    void *e;
    int a=0;
    int d=0;
    int flag=0;
    int length=0;
    int capacity=0;

    llfifo_t *my_fifo=llfifo_create(3);

    a=llfifo_enqueue(my_fifo,"hello1");
    if(a==1)
    {
        flag++;
    }
    a=llfifo_enqueue(my_fifo,"hello2");
    if(a==2)
    {
        flag++;
    }
    a=llfifo_enqueue(my_fifo,"hello3");
    if(a==3)
    {
        flag++;
    }
    a=llfifo_enqueue(my_fifo,"hello4");
    if(a==4)
    {
        flag++;
    }
    e=llfifo_dequeue(my_fifo);
    if(e=="hello1")
    {
        flag++;
    }
    e=llfifo_dequeue(my_fifo);
    if(e=="hello2")
    {
        flag++;
    }
    a=llfifo_enqueue(my_fifo,"hello5");
    if(a==3)
    {
        flag++;
    }
    a=llfifo_enqueue(my_fifo,"hello6");
    if(a==4)
    {
        flag++;
    }
    a=llfifo_enqueue(my_fifo,"hello7");
    if(a==5)
    {
        flag++;
    }
    e=llfifo_dequeue(my_fifo);
    if(e=="hello3")
    {
        flag++;
    }
    e=llfifo_dequeue(my_fifo);
    if(e=="hello4")
    {
        flag++;
    }
    e=llfifo_dequeue(my_fifo);
    if(e=="hello5")
    {
        flag++;
    }
    e=llfifo_dequeue(my_fifo);
    if(e=="hello6")
    {
        flag++;
    }
    e=llfifo_dequeue(my_fifo);
    if(e=="hello7")
    {
        flag++;
    }
    a=llfifo_enqueue(my_fifo,"hello8");
    if(a==1)
    {
        flag++;
    }
    a=llfifo_enqueue(my_fifo,"hello9");
    if(a==2)
    {
        flag++;
    }
    a=llfifo_enqueue(NULL,"hello10");
    if(a==-1)
    {
        flag++;
    }
    e=llfifo_dequeue(my_fifo);
    if(e=="hello9")
    {
        flag++;
    }
    d=llfifo_dequeue(NULL);
    if(d==-1)
    {
        flag++;
    }
    capacity = llfifo_capacity(my_fifo);
    if(capacity==5)
    {
        flag++;
    }
    length = llfifo_length(my_fifo);
    if(length==1)
    {
        flag++;
    }

    if(flag==21)
    {
        printf("Test cases passed for ll_fifo\n");
        printf("1\n\n");
    }
    else
    {
        printf("Test cases failed for ll_fifo\n");
        printf("0\n\n");
    }

    return 0;
}
