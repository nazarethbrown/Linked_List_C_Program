// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include<stdlib.h>

#include "list.h"

list_t *list_alloc() {
  list_t* ptr =(list_t*)malloc(sizeof(list_t));
  ptr -> head = NULL;
  return ptr;
                       }
void list_free(list_t *l) {
  free(l); 
}

void list_print(list_t *l) {
 node_t* temp = l -> head;
 while(temp != NULL){
   printf("%d -> ",(temp -> value));
   temp = temp -> next;
 } 
}
int list_length(list_t *l) { 
  int i = 0;
  while((l -> head) != NULL){
    i++;
    l -> head -> next;
  }
  return i; }

void list_add_to_back(list_t *l, elem value) {
  if((l -> head) == NULL){
    l -> head =(node_t*)malloc(sizeof(node_t));
    l -> head -> value = value;
    l -> head -> next = NULL;
  }
  else {
    node_t* temp = l -> head;
    while((temp -> next) != NULL){
      temp = temp -> next;
    }
    node_t* ptr = (node_t*)malloc(sizeof(node_t));
    ptr -> value = value;
    ptr -> next = NULL;
    temp -> next = ptr;
  }
}
void list_add_to_front(list_t *l, elem value) {
  if((l -> head) == NULL){
    l -> head =(node_t*)malloc(sizeof(node_t));
    l -> head -> value = value;
    l -> head -> next = NULL;
  }else{
    node_t* temp = l -> head;
    node_t* ptr = (node_t*)malloc(sizeof(node_t));
    ptr -> value =value;
    ptr -> next = temp;
    l -> head = ptr;
    
  }
}
void list_add_at_index(list_t *l, elem value, int index) {
  if((l -> head) == NULL){
    printf("\nIndex not available due to empty list.\n");
  }else{
    node_t* temp = l -> head;
    node_t* ptr = (node_t*)malloc(sizeof(node_t));
    int it = 1;
    if(index == 0){
      list_add_to_front(l,value);
    }else{
      while(it != index){
     /* temp -> next = ptr;
      ptr -> next = temp;*/
      temp = temp -> next;
      it++;
    }
    ptr -> value =value;
    ptr -> next = temp -> next;
    temp -> next = ptr;
    
    //ptr -> next = temp;
    //l -> head = ptr;
  }
}
}

elem list_remove_from_back(list_t *l) {
  
  if((l -> head) == NULL){
    printf("\nEmpty List\n");
  }else{
    node_t* temp = l -> head;
    node_t* eraser;
    while((temp -> next -> next) != NULL){
      temp = temp -> next;
    }
    eraser = temp -> next;
    temp -> next = NULL;
    free(eraser);
  }
  return -1; }
elem list_remove_from_front(list_t *l) { 
  if((l -> head) == NULL){
    printf("Empty List");
  }else{
    node_t* temp = l -> head;
    node_t* eraser;
    eraser = l -> head;
    temp = temp -> next;
    l -> head = temp;
    free(eraser);
    
  }
  return -1; }
elem list_remove_at_index(list_t *l, int index) { 
  
  if(l->head == NULL){
    return -1; 
   
  }else if(index == 0){
    return list_remove_from_front(l);
    
  }else{
    node_t* curr = l->head;
    int i;
    for(i=0;i<(index-1);i++){
      if(curr->next == NULL){
        return -1;
      }
      curr = curr->next;
    }
    node_t *temp = (node_t *) malloc(sizeof(node_t));
    temp = curr->next;
    curr->next = temp->next;
     free(temp);
    
  }
}

bool list_is_in(list_t *l, elem value) {node_t* curr = l->head;  
  while(curr != NULL){
    if (curr->value == value){
      return true;
    }else{
      curr = curr->next;
    }
  }
  return false;
}
elem list_get_elem_at(list_t *l, int index) {if(l->head == NULL){
    return -1; 
    
  }else{
    node_t* curr = l->head;
    int i;
     for(i=0;i<index;i++){
       if(curr == NULL){
         return -1;
       }
       curr = curr->next;
     }
     elem found = curr->value;
     return found;
    
  }
} 

int list_get_index_of(list_t *l, elem value) {
  if(l -> head == NULL){
    printf("Empty List");
  }else{
  int i= 0;
  node_t* temp = l -> head;
  /*while(temp != NULL){
    printf("hello");*/
    while((temp -> value)!= value){
      temp = temp -> next;
      i++;
    }
    printf("the index is %d\n",i);
  }
 
  return -1; }