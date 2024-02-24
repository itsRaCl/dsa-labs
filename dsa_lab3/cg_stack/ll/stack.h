#ifndef STACK_H
#define STACK_H

#include "element.h"
#include "heap_usage.h"
#include <stdbool.h>

typedef struct Stack Stack;

Stack *newStack();

bool isEmpty(Stack *);

bool push(Stack *, Element);

bool pop(Stack *);

Element *top(Stack *);

void freeStack(Stack *);

#endif
