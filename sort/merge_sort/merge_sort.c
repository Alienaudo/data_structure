#include <stdio.h>
#include <stdlib.h>

#include "../../lists/linked_lists/linked_list.h"

Node* findMiddle(Node* head)
{
  Node* slow = head;
  Node* fast = head->next;

  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  };

  return slow;
};

Node* merge(Node* l1, Node* l2)
{
  Node dummy;
  Node* tail = &dummy;
  dummy.next = NULL;

  while (l1 && l2)
  {
    if (l1->value < l2->value)
    {
      tail->next = l1;
      l1 = l1->next;
    }
    else
    {
      tail->next = l2;
      l2 = l2->next;
    };

    tail = tail->next;
  };

  if (l1)
  {
    tail->next = l1;
  }
  else
  {
    tail->next = l2;
  };

  return dummy.next;
};

Node* sortListRecursive(Node* head)
{
  if (!head || !head->next) return head;

  Node* middle = findMiddle(head);
  Node* afterMiddle = middle->next;
  middle->next = NULL;

  Node* left = sortListRecursive(head);
  Node* right = sortListRecursive(afterMiddle);

  return merge(left, right);
};

void mergeSort(LinkedList* list)
{
  if (!list || !list->head) return;

  list->head = sortListRecursive(list->head);
};

int main(void)
{
  LinkedList* list = createlinkedList();

  add(list, 9);
  add(list, 2);
  add(list, 4);
  add(list, 3);
  add(list, 7);
  add(list, 10);
  add(list, 5);
  add(list, 6);
  add(list, 9);
  add(list, 1);

  mergeSort(list);

  printf("Sorted list: ");
  Node* current = list->head;
  while (current)
  {
    printf("%d", current->value);
    if (current->next) printf(" -> ");
    current = current->next;
  }
  printf("\n");
  free(current);

  destroyLinkedList(list);

  return EXIT_SUCCESS;
};
