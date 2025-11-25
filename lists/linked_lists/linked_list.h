#ifndef linked_list

#define linked_list

#include <stdbool.h>

typedef struct Node
{
  int value;
  struct Node* next;
} Node;

typedef struct
{
  Node* head;
  Node* tail;
  int size;
} LinkedList;

LinkedList* createlinkedList();
int size(LinkedList* queue);
bool isEmpty(LinkedList* queue);
int peek(LinkedList* queue, bool* status);
void add(LinkedList* queue, int value);
int remove(LinkedList* queue, bool* status);
void destroyLinkedList(LinkedList* queue);

#endif
