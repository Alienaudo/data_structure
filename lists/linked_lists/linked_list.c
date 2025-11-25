#include "linked_list.h"

#include <stdbool.h>
#include <stdlib.h>

LinkedList* createlinkedList()
{
  LinkedList* list = malloc(sizeof(LinkedList));

  if (!list) return NULL;

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return list;
};

int size(LinkedList* list) { return list->size; };

bool isEmpty(LinkedList* list) { return (list->size == 0); };

int peek(LinkedList* list, bool* status)
{
  if (isEmpty(list))
  {
    *status = false;
    return EXIT_FAILURE;
  };

  *status = true;
  return list->head->value;
};

void add(LinkedList* list, int value)
{
  Node* newNode = malloc(sizeof(Node));

  if (newNode == NULL) return;

  newNode->value = value;
  newNode->next = NULL;

  if (isEmpty(list))
  {
    list->head = newNode;
    list->tail = newNode;

    list->size++;

    return;
  };

  list->tail->next = newNode;
  list->tail = newNode;

  list->size++;

  return;
};

int removeItem(LinkedList* list, bool* status)
{
  if (isEmpty(list))
  {
    *status = false;
    return EXIT_FAILURE;
  };

  *status = true;

  int value = list->head->value;
  Node* oldHead = list->head;

  if (list->size == 1)
  {
    list->head = NULL;
    list->tail = NULL;
    list->size--;

    return EXIT_SUCCESS;
  };

  list->head = list->head->next;

  free(oldHead);

  list->size--;

  return value;
};

void destroyLinkedList(LinkedList* list)
{
  if (list->size == 1)
  {
    list->head = NULL;
    list->tail = NULL;

    free(list->head);
    free(list->tail);

    return;
  };

  Node* currentNode = list->head;

  while (currentNode != NULL)
  {
    Node* tmp = currentNode;
    currentNode = currentNode->next;

    free(tmp);
  };

  free(list);

  return;
};
