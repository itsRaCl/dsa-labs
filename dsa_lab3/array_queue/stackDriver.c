#include "queue.h"
#include <stdio.h>
Element itoe (int i);
int main()
{
    Queue *s = createQueue();
    if(isEmpty(s))
        printf("queue is empty\n");
    
    enqueue(s, itoe(1));
    int value = front(s)->int_value;
    printf("Front of queue is %d\n", value);

    enqueue(s, itoe(2));
    value = front(s)->int_value;
    printf("Front of queue is %d\n", value);

    value = front(s)->int_value;
    printf("Front of queue is %d\n", value);
    
    dequeue(s);

    value = front(s)->int_value;
    printf("Front of queue is %d\n", value);
    printf("Dequeue returned %s\n", dequeue(s)?"true":"false");

    printf("Trying to dequeue an empty queue\n");
    printf("Dequeue returned %s\n", dequeue(s)?"true":"false");

    destroyQueue(s);
    return 0;
}
Element itoe (int i)
{
    Element e;
    e.int_value = i;
    e.float_value = 0;
    return e;
}
