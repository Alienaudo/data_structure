#include "stack.h"

#include <stdbool.h>
#include <stdlib.h>

Stack* createStack(int capacity)
{
  if (capacity <= 0) return NULL;

  Stack* stack = malloc(sizeof(Stack));

  if (stack == NULL) return NULL;

  stack->collection = malloc(sizeof(Stack) * capacity);

  if (stack->collection == NULL)
  {
    free(stack);
    return NULL;
  };

  stack->capacity = capacity;
  stack->size = 0;

  return stack;
};

void destroyStack(Stack* stack)
{
  free(stack->collection);
  free(stack);
  return;
};

bool isFull(Stack* stack) { return stack->capacity == stack->size; };

bool isEmpty(Stack* stack) { return stack->size == 0; };

bool push(Stack* stack, int item)
{
  if (isFull(stack)) return false;

  stack->collection[stack->size] = item;
  stack->size++;

  return true;
};

bool pop(Stack* stack, int* item)
{
  if (isEmpty(stack)) return false;
  if (stack == NULL) return false;
  if (item == NULL) return false;

  stack->size--;
  *item = stack->collection[stack->size];

  return true;
};

bool peek(Stack* stack, int* item)
{
  if (isEmpty(stack)) return false;

  *item = stack->collection[stack->size - 1];

  return true;
};
