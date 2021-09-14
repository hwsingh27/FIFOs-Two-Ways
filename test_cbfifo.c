/**
 * @file test_cbfifo.c
 * @brief test function for cbfifo has been implemented to test several cases for
 * the efficient working of the cbfifo.c
 * @author Harshwardhan Singh
 * @date September 13th 2021
 * @tools Code Blocks 20.03
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "CBFIFO.h"

/**
 * @brief function for the test cases, several enqueue and
 * dequeue functions have been performed in addition to the
 * length and capacity functions to check various test cases.
 * Declared one flag that increments when any of the test cases
 * is passed. In order to pass all the test cases, the value of
 * the flag should be equal to the number of test cases passed.
 *
 * @param does not have any parameter
 * @return the functions returns "Test cases passed for cb_fifo" and "1"
 * if all the test cases are passed otherwise returns "Test cases failed
 * for cb_fifo" and "0" if any of the test cases implemented is failed.
 */
int test_cbfifo()
{
    uint8_t debuff[128];
    char *str=debuff;
    size_t res=0;
    size_t res2=0;
    size_t len;
    size_t cap;
    int flag=0;

    //multiple operations together
    res=cbfifo_enqueue("helloralphie",120);
    if(res==120)
    {
        flag++;
    }
    res2=cbfifo_dequeue(str,24);
    if(res2==24)
    {
        flag++;
    }
    res=cbfifo_enqueue("helloralphie",12);
    if(res==12)
    {
        flag++;
    }
    res2=cbfifo_dequeue(str,106);
    if(res2==106)
    {
        flag++;
    }
    res=cbfifo_enqueue("helloralphie",12);
    if(res==12)
    {
        flag++;
    }
    res2=cbfifo_dequeue(str,20);
    if(res2==14)
    {
        flag++;
    }
    res=cbfifo_enqueue("helloralphie",127);
    if(res==127)
    {
        flag++;
    }

    len=cbfifo_length();
    if(len==127)
    {
        flag++;
    }
    cap=cbfifo_capacity();
    if(cap==128)
    {
        flag++;
    }

    //with NULL pointer
    res2=cbfifo_dequeue(str,127);
    if(res2==127)
    {
        flag++;
    }
    res=cbfifo_enqueue(NULL,0);
    if(res==-1)
    {
        flag++;
    }
    res2=cbfifo_dequeue(NULL,3);
    if(res2==-1)
    {
        flag++;
    }

    //testing when 0 bytes passed
    res=cbfifo_enqueue("helloralphie",0);
    if(res==0)
    {
        flag++;
    }
    res2=cbfifo_dequeue(str,0);
    if(res2==0)
    {
        flag++;
    }
    res = cbfifo_enqueue("helloworld123",7);
    if(res==7)
    {
        flag++;
    }
    res2 = cbfifo_dequeue(str,0);
    if(res2==0)
    {
        flag++;
    }

    //testing with different datatypes
    int x=12;
    float m=1.2;
    void *b=&x;
    void *c=&m;

    res=cbfifo_enqueue(b,4);
    if(res==4)
    {
        flag++;
    }
    res=cbfifo_enqueue(b,1);
    if(res==1)
    {
        flag++;
    }
    res=cbfifo_enqueue(c,3);
    if(res==3)
    {
        flag++;
    }
    res=cbfifo_enqueue(c,1);
    if(res==1)
    {
        flag++;
    }

    if(flag==20)
    {
        printf("Test cases passed for cb_fifo\n");
        printf("1\n");
    }
    else
    {
        printf("Test cases failed for cb_fifo\n");
        printf("0\n");
    }

    return 0;
}
