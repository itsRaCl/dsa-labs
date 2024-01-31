#include "stack.h"
#include <stdio.h>
#include <sys/time.h>

struct timeval t1, t2;

Element itoe(int i);
int main() {
  gettimeofday(&t1, NULL);
  Stack *s = newStack();
  gettimeofday(&t2, NULL);

  double create = (t2.tv_sec - t1.tv_sec) * 1e6;
  create = (create + (t2.tv_usec - t1.tv_usec)) * 1e-6;
  gettimeofday(&t1, NULL);
  if (isEmpty(s)) {
    gettimeofday(&t2, NULL);
    printf("Stack is empty\n");
  }

  double empty = (t2.tv_sec - t1.tv_sec) * 1e6;
  empty = (empty + (t2.tv_usec - t1.tv_usec)) * 1e-6;

  gettimeofday(&t1, NULL);
  push(s, itoe(1));
  gettimeofday(&t2, NULL);
  double psh1 = (t2.tv_sec - t1.tv_sec) * 1e6;
  psh1 = (psh1 + (t2.tv_usec - t1.tv_usec)) * 1e-6;

  gettimeofday(&t1, NULL);
  int value = top(s)->int_value;
  gettimeofday(&t2, NULL);

  double top1 = (t2.tv_sec - t1.tv_sec) * 1e6;
  top1 = (top1 + (t2.tv_usec - t1.tv_usec)) * 1e-6;
  printf("Top of stack is %d\n", value);

  gettimeofday(&t1, NULL);
  push(s, itoe(2));
  gettimeofday(&t2, NULL);
  double psh2 = (t2.tv_sec - t1.tv_sec) * 1e6;
  psh2 = (psh2 + (t2.tv_usec - t1.tv_usec)) * 1e-6;
  value = top(s)->int_value;
  printf("Top of stack is %d\n", value);

  value = top(s)->int_value;
  printf("Top of stack is %d\n", value);

  gettimeofday(&t1, NULL);
  pop(s);
  gettimeofday(&t2, NULL);
  double pop1 = (t2.tv_sec - t1.tv_sec) * 1e6;
  pop1 = (pop1 + (t2.tv_usec - t1.tv_usec)) * 1e-6;

  value = top(s)->int_value;
  printf("Top of stack is %d\n", value);
  printf("Pop returned %s\n", pop(s) ? "true" : "false");

  printf("Trying to pop an empty stack\n");
  printf("Pop returned %s\n", pop(s) ? "true" : "false");

  printf("%lu\n", heapMemoryAllocated);

  gettimeofday(&t1, NULL);
  freeStack(s);
  gettimeofday(&t2, NULL);

  double free1 = (t2.tv_sec - t1.tv_sec) * 1e6;
  free1 = (free1 + (t2.tv_usec - t1.tv_usec)) * 1e-6;

  printf("%lu\n", heapMemoryAllocated);

  printf("Time taken to create: %lf\n Time taken to push1: %lf\nTime takem to "
         "push2: %lf\n Time taken to pop: %lf\n Time taken to top: %lf\n Time "
         "taken to free: %lf\n",
         create, psh1, psh2, pop1, top1, free1);
  return 0;
}
Element itoe(int i) {
  Element e;
  e.int_value = i;
  e.float_value = 0;

  return e;
}
