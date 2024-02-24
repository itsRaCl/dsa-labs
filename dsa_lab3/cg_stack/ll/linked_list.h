#ifndef LL_H
#define LL_H

#include "element.h"
#include "heap_usage.h"

typedef struct node node;

struct node {
  Element data;
  node *next;
};

typedef node *NODE;

struct linked_list {
  int count;
  NODE head;
};

typedef struct linked_list linked_list;
typedef linked_list *LIST;

LIST createNewList();

NODE createNewNode(Element);

void insertNodeIntoList(NODE, LIST);

void removeFirstNode(LIST);

void insertNodeAtEnd(NODE, LIST);

#endif
