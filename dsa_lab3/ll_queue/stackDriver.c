#include "queue.h"
#include "heap_usage.h"
#include <stdio.h>
#include <sys/time.h>

struct timeval t1, t2;

Element itoe(int i);
int main() {
  gettimeofday(&t1, NULL);
  Queue *s = createQueue();
  gettimeofday(&t2, NULL);

  double create = (t2.tv_sec - t1.tv_sec) * 1e6;
  create = (create + (t2.tv_usec - t1.tv_usec)) * 1e-6;
  gettimeofday(&t1, NULL);
  if (isEmpty(s)) {
    gettimeofday(&t2, NULL);
    printf("Queue is empty\n");
  }

  double empty = (t2.tv_sec - t1.tv_sec) * 1e6;
  empty = (empty + (t2.tv_usec - t1.tv_usec)) * 1e-6;

  gettimeofday(&t1, NULL);
  enqueue(s, itoe(1));
  gettimeofday(&t2, NULL);
  double psh1 = (t2.tv_sec - t1.tv_sec) * 1e6;
  psh1 = (psh1 + (t2.tv_usec - t1.tv_usec)) * 1e-6;

  gettimeofday(&t1, NULL);
  int value = front(s)->int_value;
  gettimeofday(&t2, NULL);

  double front1 = (t2.tv_sec - t1.tv_sec) * 1e6;
  front1 = (front1 + (t2.tv_usec - t1.tv_usec)) * 1e-6;
  printf("Front of queue is %d\n", value);

  gettimeofday(&t1, NULL);
  enqueue(s, itoe(2));
  gettimeofday(&t2, NULL);
  double psh2 = (t2.tv_sec - t1.tv_sec) * 1e6;
  psh2 = (psh2 + (t2.tv_usec - t1.tv_usec)) * 1e-6;
  value = front(s)->int_value;
  printf("Front of queue is %d\n", value);

  value = front(s)->int_value;
  printf("Front of queue is %d\n", value);

  gettimeofday(&t1, NULL);
  dequeue(s);
  gettimeofday(&t2, NULL);
  double dequeue1 = (t2.tv_sec - t1.tv_sec) * 1e6;
  dequeue1 = (dequeue1 + (t2.tv_usec - t1.tv_usec)) * 1e-6;

  value = front(s)->int_value;
  printf("Front of queue is %d\n", value);
  printf("Dequeue returned %s\n", dequeue(s) ? "true" : "false");

  printf("Trying to dequeue an empty queue\n");
  printf("Dequeue returned %s\n", dequeue(s) ? "true" : "false");

  printf("%lu\n", heapMemoryAllocated);

  gettimeofday(&t1, NULL);
  destroyQueue(s);
  gettimeofday(&t2, NULL);

  double free1 = (t2.tv_sec - t1.tv_sec) * 1e6;
  free1 = (free1 + (t2.tv_usec - t1.tv_usec)) * 1e-6;

  printf("%lu\n", heapMemoryAllocated);

  printf("Time taken to create: %lf\n Time taken to enqueue1: %lf\nTime takem to "
         "enqueue2: %lf\n Time taken to dequeue: %lf\n Time taken to front: %lf\n Time "
         "taken to free: %lf\n",
         create, psh1, psh2, dequeue1, front1, free1);
  return 0;
}
Element itoe(int i) {
  Element e;
  e.int_value = i;
  e.float_value = 0;

  return e;
}
