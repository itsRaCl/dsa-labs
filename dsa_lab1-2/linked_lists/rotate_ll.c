#include <stdio.h>
#include <stdlib.h>
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

void rotate_list(LIST ll){
	int k;
	printf("Enter the position of element to rotate by: ");
	scanf("%d", &k);
	for (int i=0; i<k; i++){
		NODE temp = ll->head;
		ll->head = temp->next;
		NODE temp2 = ll->head;
		while (temp2->next !=NULL){
			temp2=temp2->next;
		}
		temp2-> next = temp;
		temp->next = NULL;
	}	
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
	rotate_list(ll);
	printList(ll);
}
