#include "list.h"

int main() {
  linkedList_t test = linkedList_create();
  char a[5] = "welp";
  linkedList_push(test, "bob");
  linkedList_push(test, "second");
  linkedList_push(test, a);
  
  printf("length is %i\n", linkedList_length(test));
  linkedList_print(test);
  printf("find index 1 %s\n", linkedList_peekItemByIndex(test, 1));
  printf("it contains welp %d\n", linkedList_containsItem(test, a));

  printf("\npulled %s\n", linkedList_pull(test));
  linkedList_print(test);
  printf("length is %i\n", linkedList_length(test));
  return 0;
}
