/*
*	Stack
*	Author: J.R.Dermoudy
*	Version: May 2021
*
*	This file holds the specification of the Stack.
*
*	This file is complete.
*/

#ifndef _STACK
#define _STACK

#include <stdbool.h>

struct stack_int;
typedef struct stack_int *stack;

void init_stack(stack *sp);
bool is_empty_stack(stack s);
void push(stack s, void *i);
void *top(stack s);
void pop(stack s);

#endif