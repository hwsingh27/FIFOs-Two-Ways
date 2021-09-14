/**
 * @file llfifo.c
 * @brief six functions have been implemented for the linked list
 * problem statement for creating the linked list, inserting, deleting
 * the linked list elements, length and capacity functions to determine
 * the length and size of the linked list.

 * @author Harshwardhan Singh
 * @date September 13th 2021
 * @tools Code Blocks 20.03
 * @application links:
 * Referred Geeks for Geeks to recall the working of linked list.
 * https://www.geeksforgeeks.org/data-structures/linked-list/
 */

#include <stdio.h>
#include<stdlib.h>
#include "llfifo.h"

typedef struct llfifo_s
{
    void *data;
    struct llfifo_s *next;
}llfifo_t;

int len=0;
int cap=0;

llfifo_t *first = NULL;
llfifo_t *last = NULL;

/**
 * @brief function to create and initialise the FIFO
 *
 * @param passing the capacity of integer type as an initial size of the FIFO.
 * @return the functions returns a pointer to the newly-created llfifo_t instance and
 * returns NULL in case of an error.
 */
llfifo_t *llfifo_create(int capacity)
{
    if(capacity<0)
    {
        return NULL;
    }
    cap=capacity;
    int i;
    llfifo_t *t,*l;
    first=(llfifo_t *)malloc(sizeof(llfifo_t));
    first->data=0;
    first->next=NULL;
    l=first;

    for(i=1;i<capacity;i++)
    {
        t=(llfifo_t *)malloc(sizeof(llfifo_t));
        t->data=0;
        t->next=NULL;
        l->next=t;
        l=t;
    }
    l->next=first;
    last=first;
    return first;
}

/**
 * @brief the function enqueues an element onto the FIFO, growing the FIFO
 * by additional elements
 *
 * @param fifo the FIFO given in the problem statement, element that is to be
 * enqueued which cannot be NULL
 * @return function returns the new length of the FIFO on success, returns -1
 * on failure, it is an error to attempt to enqueue the NULL pointer.
 */
int llfifo_enqueue(llfifo_t *fifo, void *element)
{
    if(fifo==NULL)
    {
        return -1;
    }
    if(last->data==0)
    {
        last->data=element;
        len++;
        return len;
    }
    else
    {
        if(last->next->data==0)
        {
            last->next->data=element;
            len++;
            last=last->next;
            return len;
        }
        else
        {
            llfifo_t *t;
            t=(llfifo_t *)malloc(sizeof(llfifo_t));
            t->data=element;
            t->next=first;
            last->next=t;
            last=last->next;
            len++;
            cap++;
            return len;
        }
    }
}

/**
 * @brief the function dequeues an element from the FIFO thereby reducing the
 * number of element in the FIFO
 *
 * @param fifo the FIFO given in the problem statement
 * @return function returns the dequeued element from the FIFO on success, returns -1
 * on failure, and returns NULL if the FIFO was empty.
 */
void *llfifo_dequeue(llfifo_t *fifo)
{
    //printf("%s", *fifo);
    if(fifo==NULL)
    {
        return -1;
    }
    if(len==0)
    {
        return NULL;
    }
    else
    {
        void *d=first->data;
        first->data=0;
        first=first->next;
            //printf("%s", *fifo);

        len--;
        return d;   //TODO
    }
}

/**
 * @brief the function computes the length of the FIFO before or after performing
 * enqueue and dequeue functions.
 *
 * @param fifo the FIFO given in the problem statement
 * @return function returns the length of the FIFO (number of elements in the FIFO)
 * on success, returns -1 on failure
 */
int llfifo_length(llfifo_t *fifo)
{
    if(fifo==NULL)
    {
        return -1;
    }
    return len;
}

/**
 * @brief the function computes the size or the capacity of the FIFO
 *
 * @param fifo the FIFO given in the problem statement
 * @return function returns the size (capacity) of the FIFO on success, returns -1
 * on failure
 */
int llfifo_capacity(llfifo_t *fifo)
{
    if(fifo==NULL)
    {
        return -1;
    }
    return cap;
}

/**
 * @brief the function frees all the dynamically allocated memories. FIFO cannot
 * be used again after calling this function
 *
 * @param fifo the FIFO given in the problem statement
 * @return function does not return anything
 */
void llfifo_destroy(llfifo_t *fifo)
{
    if(fifo==NULL)
    {
        return -1;
    }
    llfifo_t *temp = fifo;
    for(int i=0;i<cap;i++)
    {
        temp=fifo;
        fifo=fifo->next;
        free(temp);
    }
}
