#include "queue.h"
#include "linked_list.h"
#include <stdlib.h>

#define MAX_QUEUE_LEN 1000

struct Queue{
	LIST ll;
};


bool isEmpty(Queue *q){
	if (q->ll->head == NULL) return true;
	return false;
}

Queue *createQueue(){
	Queue * q= (Queue *)myalloc(sizeof(Queue));
	q->ll = createNewList();
	return q;
}

bool enqueue(Queue* q, Element e){
	insertNodeAtEnd(createNewNode(e), q->ll);
	return true;
}

bool dequeue(Queue* q){
	if (isEmpty(q)){
		return false;	
	}
	removeFirstNode(q->ll);
	return true;
}


Element* front(Queue *q){
	return &(q->ll->head->data);
}

int size(Queue* q){
	return q->ll->count;
}

void destroyQueue(Queue* q){
	LIST ll = q->ll;
	while (ll->count != 0){
		removeFirstNode(ll);	
	}	
	myfree(ll);
	myfree(q);
}
