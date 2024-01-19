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
void insertAfter(int searchEle, NODE n1, LIST l1)
{
	if(l1->head==NULL)
	{
		l1->head = n1;
		n1->next = NULL;
		l1->count++;
	}
	else
	{
		NODE temp = l1->head;
		NODE prev = temp;
		while(temp!=NULL)
		{
			if (temp->ele == searchEle)
				break;
			prev = temp;
			temp = temp->next;
		}
		if(temp==NULL)
		{
			printf("Element not found\n");
			return;
		}
		else
		{
			if(temp->next == NULL)
			{
				temp->next = n1;
				n1->next = NULL;
				l1->count++;
			}
			else
			{
				prev = temp;
				temp = temp->next;
				prev->next = n1;
				n1->next = temp;
				l1->count++;
			}
			return;
		}
	}
	return;
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

void insertFirst(LIST ll){
	int value;
	printf("Print the new value to be stored: ");
	scanf("%d", &value);
	NODE temp = ll->head;
	NODE n = createNewNode(value);
	n->next= temp;
	ll->head = n;
	(ll->count)++;
}

void deleteFirst(LIST ll){

	NODE n = ll->head->next;
	free(ll->head);
	ll->head = n;
	ll->count --;
}

int search(LIST ll){
	int value;
	printf("Which value do you want to search? ");
	scanf("%d", &value);
	NODE temp=ll->head;
	int pos=0;
	while(temp!=NULL){
		if (temp->ele == value){
			return pos;
		}else{
			temp = temp->next;
		}
		pos++;
	}
	return -1;

}

void searchDelete(LIST ll){
	int value;
	printf("Which value do you want to search? ");
	scanf("%d", &value);
	NODE find=ll->head;
	int pos=0;
	while(find->next!=NULL){
		if (find->next->ele == value){
			NODE temp = find->next;
			find->next = temp->next;
			free(temp);
			ll->count --;
			return;
		}else{
			find = find->next;
		}
		pos++;
	}
	return;
	
}


int main(){
	// functions to be implemented
	// 	1. Create new list
	// 	2. Insert after
	// 	3. create new node
	// 	4. print
	// ==========================
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
	char  menu[] = "What do you want to do?\n1. Print the list\n2. Insert at start\n3. Delete the first element\n4. Search for a value\n5. Delete a specific element\n==>";
	int input=-1;
	while (input!=0){
		printf("%s", menu);
		scanf("%d", &input);
		switch(input){
		case 1: printList(ll);break;
		case 2: insertFirst(ll); break;
		case 3: deleteFirst(ll); break;
		case 4: printf("Element found at position %d\n", search(ll)); break;
		case 5: searchDelete(ll); break;
		default: continue;
	}}
	printf("Have a nice day!");
	return 0;
}


