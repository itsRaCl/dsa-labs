#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node* NODE;
struct node{
	int ele;
	NODE next;
};
typedef struct linked_list* LIST;
struct linked_list{
	int count;
	NODE head;
};
LIST createNewList()
{
	LIST myList;
	myList = (LIST) malloc(sizeof(struct linked_list));
	myList->count=0;
	myList->head=NULL;
	return myList;
}
NODE createNewNode(int value)
{
	NODE myNode;
	myNode = (NODE) malloc(sizeof(struct node));
	myNode->ele=value;
	myNode->next=NULL;
	return myNode;
}

void printList(LIST l1)
{
	NODE temp = l1->head;
	printf("[HEAD] ->");
	while(temp != NULL)
	{
		printf(" %d ->", temp->ele);
		temp = temp->next;
	}
	printf(" [NULL]\n");
}

bool hasCycle(LIST ll){
	NODE hare = ll->head;
	NODE tortoise= ll->head;
	while (hare->next != NULL && hare->next->next != NULL && tortoise->next != NULL){
		hare = hare->next->next;
		tortoise = tortoise->next;
		if (hare == tortoise) return true;
	}
	return false;
}

int main(){
	int n;
	LIST ll = createNewList();
	printf("Enter the lenght of initial list: ");
	scanf("%d", &n);
	for (int i=0; i<n;i++){
		int x;
		printf("Enter the number to be stored: ");
		scanf("%d" , &x);
		NODE n = createNewNode(x);
		printf("%d\n", n->ele);
		if (ll->count == 0){
			ll->head = n;
			(ll->count)++;
		}else{
			NODE find = ll->head;
			while (find->next!=NULL){
				find = find->next;
			}
			find->next = n;
			(ll->count)++;
		}
		
	}
	printList(ll);
	printf("%d\n", hasCycle(ll));
	NODE temp = ll->head;
	while (temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = ll->head;
	printf("%d\n", hasCycle(ll));
}
