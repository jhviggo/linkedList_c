#include "list.h"

typedef struct linkedList_st {
  void* item;
	linkedList_t next;
} node_t;

/* Create */
linkedList_t linkedList_create(void) {
  linkedList_t _list;
  _list = calloc(sizeof(node_t), 1);
  _list->item = NULL;
  _list->next = NULL;
  return _list;
}

/* Push */
linkedList_return_codes_t linkedList_push(linkedList_t list, void *item) {
  if (list->item == NULL) {
    list->item = item;
    return LINKED_LIST_OK;
  }
  
  linkedList_t current = list;
  while(current->next != NULL) {
    current = current->next;
  }

  linkedList_t _newNode = calloc(sizeof(node_t), 1);
  _newNode->item = item;
  current->next = _newNode;

  return LINKED_LIST_OK;
}

/* Pull */
void * linkedList_pull(linkedList_t list) {
  linkedList_t *head = &list;
  void* tempItem = list->item;
  *list = *list->next;
  free(head);
  return tempItem;
}

/* Peek */
void* linkedList_peekItemByIndex(linkedList_t list, uint16_t index) {
  linkedList_t temp = list;
  int i = 0;

  while (temp != NULL) {
    if (index == i) {
      return temp->item;
    }
    i += 1;
    temp = temp->next;
  }

  return NULL;
}

/* Contains item */
linkedList_return_codes_t linkedList_containsItem(linkedList_t list, void *item) {
  linkedList_t temp = list;

  while (temp != NULL) {
    if (item == temp->item) {
      return LINKED_LIST_OK;
    }
    temp = temp->next;
  }
  return LINKED_LIST_NOT_FOUND;
}

/* Length */
int linkedList_length(linkedList_t list) {
  linkedList_t temp = list;
  int len = 0;

  while (temp != NULL && temp->item != NULL) {
    len += 1;
    temp = temp->next;
  }
  return len;
}

/* Clear */
void linkedList_clear(linkedList_t list) {
  linkedList_t temp = list;

  while (temp != NULL) {
    free(&temp);
    temp = temp->next;
  }
  list->item = NULL;
  list->next = NULL;
}

/* Remove item */
linkedList_return_codes_t linkedList_removeItem(linkedList_t list, void *item) {
  linkedList_t temp = list->next;
  linkedList_t previous = list;

  if (list->item == item) {
    list->item = NULL;
    return LINKED_LIST_OK;
  }

  while (temp != NULL) {
    if (temp->item == item) {
      previous->next = temp->next;
      free(&temp);
      return LINKED_LIST_OK;
    }
    previous = temp;
    temp = temp->next;
  }
  return LINKED_LIST_NOT_FOUND;
}


void linkedList_print(linkedList_t list) {
  linkedList_t temp = list;

  while (temp != NULL) {
    printf("%s\n", temp->item);
    temp = temp->next;
  }
}
