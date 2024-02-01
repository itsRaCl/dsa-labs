#include "queue.h"
#include <stdlib.h>

#define MAX_QUEUE_LEN 1000

struct Queue{
	Element data[MAX_QUEUE_LEN];
	int rear;
};


bool isEmpty(Queue *q){
	if (q->rear == -1) return true;
	return false;
}

Queue *createQueue(){
	Queue * q= (Queue *)malloc(sizeof(Queue));
	q->rear = -1;

	return q;
}

bool enqueue(Queue* q, Element e){
	if (q->rear== MAX_QUEUE_LEN -1){
		return false;
	}

	q->data[++(q->rear)] = e;
}

bool dequeue(Queue* q){
	if (isEmpty(q)){
		return false;	
	}
	for (int i=0; i<q->rear; i++){
		q->data[i] = q->data[i+1];
	}	
	(q->rear)--;
	return true;
}


Element* front(Queue *q){
	if (isEmpty(q)){
		return NULL;
	}
	return &(q->data[0]);
}

int size(Queue* q){
	return (q->rear)+1;
}

void destroyQueue(Queue* q){
	free(q);
}
