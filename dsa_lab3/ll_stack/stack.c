#include "stack.h"
#include "linked_list.h"
#include <stdlib.h>

struct Stack {
  LIST ll;
};

Stack *newStack() {
  Stack *s = (Stack *)myalloc(sizeof(Stack));
  s->ll = createNewList();
  return s;
}

bool isEmpty(Stack *s) {
  if (s->ll->count == 0 && s->ll->head == NULL) {
    return true;
  }
  return false;
}

bool push(Stack *s, Element e) {
  insertNodeIntoList(createNewNode(e), s->ll);
  return true;
}

bool pop(Stack *s) {
  if (s->ll->head == NULL) {
    return false;
  }
  removeFirstNode(s->ll);
  return true;
}

Element *top(Stack *s) { return &(s->ll->head->data); }

void freeStack(Stack *s) {
  LIST ll = s->ll;
  while (ll->count > 0) {
    removeFirstNode(ll);
  }

  myfree(ll);
  myfree(s);
}
