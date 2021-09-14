/*********************************************************************************
 * Copyright (c) 2021 by Harshwardhan Singh
 *
 * Redistribution, modification or use of this program in source or binary forms
 * is permitted as long as the files maintain this copyright. Users are permitted
 * to modify this and use it to learn about the field of embedded software.
 * Harshwardhan Singh and the University of Colorado are not liable for any misuse
 * of this material.
**********************************************************************************
/**
 * @file main.c
 * @brief two test functions are called namely test_llfifo and test_cbfifo
 * for linked list and circular buffer respectively. These functions call the
 * production code files in order to run the program.
 *
 * @author Harshwardhan Singh
 * @date September 13th 2021
 * @tools Code Blocks 20.03
 */

#include<stdio.h>

int main()
{
    test_llfifo();
    test_cbfifo();
    return 0;
}
