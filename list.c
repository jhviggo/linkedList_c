#include "list.h"

typedef struct linkedList_st {
  void* item;
	linkedList_t next;
} node_t;

linkedList_t linkedList_create(void) {
  linkedList_t _list;
  _list = calloc(sizeof(node_t), 1);
  _list->item = NULL;
  _list->next = NULL;
  return _list;
}


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

void * linkedList_pull(linkedList_t list) {

}

void* linkedList_peekItemByIndex(linkedList_t list, uint16_t index) {

}

linkedList_return_codes_t linkedList_containsItem(linkedList_t list, void *item) {

}

int linkedList_length(linkedList_t list) {

}

void linkedList_clear(linkedList_t list) {

}

linkedList_return_codes_t linkedList_removeItem(linkedList_t list, void *item) {

}

linkedList_iterator_t linkedList_getIterator(linkedList_t list) {

}

void *linkedList_iteratorNext(linkedList_t list, linkedList_iterator_t *iterator) {

}