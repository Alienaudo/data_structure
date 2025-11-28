#ifndef stack_h

#define stack_h

#include <stdbool.h>

typedef struct
{
  int* collection;
  int capacity;
  int size;
} Stack;

Stack* createStack(int capacity);
void destroyStack(Stack* stack);
bool isFull(Stack* stack);
bool isEmpty(Stack* stack);
bool push(Stack* stack, int item);
bool pop(Stack* stack, int* item);
bool peek(Stack* stack, int* item);

#endif
