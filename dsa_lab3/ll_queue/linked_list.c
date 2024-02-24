#include "linked_list.h"
#include "heap_usage.h"
#include <stdlib.h>

LIST createNewList() {
  LIST ll = (LIST)myalloc(sizeof(linked_list));
  ll->count = 0;
  ll->head = NULL;
  return ll;
}

NODE createNewNode(Element d) {
  NODE n = (NODE)myalloc(sizeof(node));
  n->data = d;
  n->next = NULL;
  return n;
}

void insertNodeIntoList(NODE node, LIST list) {
  node->next = list->head;
  list->head = node;
  list->count++;
}

void removeFirstNode(LIST list) {
  NODE temp = list->head;
  list->head = temp->next;
  list->count--;
  myfree(temp);
}

void insertNodeAtEnd(NODE node, LIST list) {
	if(list->head == NULL){
		list->head = node;
		list->count++;
		return;
	}
	NODE temp = list->head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = node;
	list->count++;
}
