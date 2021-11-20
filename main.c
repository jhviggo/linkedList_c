#include "list.h"

int main() {
  linkedList_t test = linkedList_create();
  char a[5] = "welp";
  char b[10] = "second";
  linkedList_push(test, "bob");
  linkedList_push(test, b);
  linkedList_push(test, a);
  
  printf("length is %i\n", linkedList_length(test));
  linkedList_print(test);
  printf("find index 1 %s\n", linkedList_peekItemByIndex(test, 1));
  printf("it contains welp %d\n", linkedList_containsItem(test, a));

  printf("\npulled %s\n", linkedList_pull(test));
  linkedList_print(test);
  printf("length is %i\n\n", linkedList_length(test));

  linkedList_removeItem(test, b);
  linkedList_print(test);
  printf("\n\n");

  linkedList_clear(test);
  printf("Cleared list.\n");
  linkedList_print(test);
  printf("length is %i\n", linkedList_length(test));
  return 0;
}
