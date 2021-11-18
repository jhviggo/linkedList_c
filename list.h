#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum {
	LINKED_LIST_OK,
	LINKED_LIST_EMPTY,
	LINKED_LIST_FULL,
	LINKED_LIST_NOT_FOUND,
	LINKED_LIST_FOUND
} linkedList_return_codes_t;

typedef struct linkedList_st* linkedList_t;
typedef struct linkedList_node* linkedList_iterator_t;

linkedList_t linkedList_create(void);

linkedList_return_codes_t linkedList_push(linkedList_t list, void *item);

void* linkedList_pull(linkedList_t list);

void* linkedList_peekItemByIndex(linkedList_t list, uint16_t index);

linkedList_return_codes_t linkedList_containsItem(linkedList_t list, void *item);

int linkedList_length(linkedList_t list);

void linkedList_clear(linkedList_t list);

linkedList_return_codes_t linkedList_removeItem(linkedList_t list, void *item);

linkedList_iterator_t linkedList_getIterator(linkedList_t list);

void* linkedList_iteratorNext(linkedList_t list, linkedList_iterator_t *iterator);


void linkedList_print(linkedList_t list);