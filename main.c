#include "list.h"
#include <stdio.h>

void print_list(struct linkedList_t list) {
  linkedList_t* current = list;

  while(current->next != NULL) {
    current = current->next;
  }
}

int main() {
  linkedList_t list = linkedList_create();

  return 0;
}
