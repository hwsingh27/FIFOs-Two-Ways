/**
 * @file cbfifo.c
 * @brief four functions have been implemented for the circular buffer
 * problem statement for inserting, deleting the circular buffer elements,
 * length and capacity functions to determine the length and size of the buffer.

 * @author Harshwardhan Singh
 * @date September 13th 2021
 * @tools Code Blocks 20.03
 * @application links:
 * Referred Geeks for Geeks to recall the working of circular buffer.
 * https://www.geeksforgeeks.org/circular-queue-set-1-introduction-array-implementation/
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "cbfifo.h"

#define SIZE (128)

uint8_t cbuff[SIZE];
int front=0;
int rear=0;
size_t length=0;

/**
 * @brief function enqueues the data onto the FIFO, up to the limit
 * of the available FIFO size or capacity.
 *
 * @param "buf" pointer to the data and "nbyte" maximum number of bytes to enqueue.
 * @return the function returns the number of bytes actually enqueued that could be 0,
 * and returns -1 in case of an error.
 */
size_t cbfifo_enqueue(void *buf, size_t nbyte)
{
    if(buf==NULL)
    {
        return -1;
    }
    size_t flag=0;
    while(length!=SIZE && flag<nbyte)
    {
        cbuff[rear]=*(uint8_t *)(buf+flag);
        length++;
        rear=(rear+1)%SIZE;
        flag++;
    }
    return flag;
}

/**
 * @brief function attempts to remove up to nbytes of data from the FIFO
 * Removed data is copied into the buffer pointed by buf.
 *
 * @param "buf" pointed to the destination for the dequeued data and
 * bytes of data requested.
 * @return the functions returns the number of bytes actually copied, which
 * can be between 0 and nbyte and returns -1 in case of an error.
 */
size_t cbfifo_dequeue(void *buf, size_t nbyte)
{
    if(buf==NULL)
    {
        return -1;
    }
    size_t flag=0;
    int i=0;
    while(length!=0 && flag<nbyte)
    {
        *(uint8_t *)(buf+flag)=cbuff[i++];
        length--;
        front=(front+1)%SIZE;
        flag++;
    }
    return flag;
}

/**
 * @brief function to compute the number of bytes currently on the FIFO.
 *
 * @param no parameter is required for this function.
 * @return the functions returns a number of bytes currently available to be dequeued
 * from the FIFO.
 */
size_t cbfifo_length()
{
    return length;
}

/**
 * @brief function to compute the total size of the FIFO.
 *
 * @param no parameter is required for this function.
 * @return the functions returns a capacity or total size of the FIFO.
 */
size_t cbfifo_capacity()
{
    return SIZE;
}
