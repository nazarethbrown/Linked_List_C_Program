#include <stdio.h>

#include "list.h"

int main() {
  list_t* listy = list_alloc();
  list_add_to_back(listy, 12);
  list_add_to_back(listy,13);
  list_add_to_front(listy, 3);
  list_add_to_back(listy,116);
  list_add_to_back(listy,19);
  list_add_to_front(listy, 0);
  list_add_to_front(listy, 78);
  list_add_at_index(listy, 365, 6);
  //list_remove_from_back(listy);
  //list_remove_from_front(listy);
  //list_free(listy);
  list_get_index_of(listy,3);
  list_is_in(listy,116);
  list_get_elem_at(listy,0);
  list_print(listy);
  printf("\nTests for linked list implementation\n");
  return 0;
}