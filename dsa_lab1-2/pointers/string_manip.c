#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 1000

char menu[] = "Options:\n\t1. Append\n\t2. Prepend\n\t3. Delete\n\t4. Length\n\t5. Print\n\t0. Exit\n==>";

typedef struct {
	char ** arr;
	int len;
} strArr;


int len(strArr* strings){
	return strings->len;
}

void print(strArr* strings){
	for (int i=0; i< len(strings); i++){
		printf("%s\n", strings->arr[i]);
	}
}



void append(strArr* strings){
	int current_length = len(strings);
	strings->arr = realloc(strings->arr, current_length + 1);
	strings->arr[current_length] = calloc(MAX_LEN, sizeof(char));
	printf("String to be appended: ");
	scanf("%s", (strings->arr)[current_length]);
	(strings->len)++;

}

void prepend (strArr* strings){
	int current_length = len(strings);
	char ** copy_strings = calloc(current_length + 1, sizeof(char *));
	for (int i=0; i< current_length+1; i++){
		copy_strings[i] = calloc(MAX_LEN, sizeof(char));
	}
	printf("String to be prepended: ");
	scanf("%s", *(copy_strings));
	for (int i=0; i<current_length; i++){
		copy_strings[i+1] = strings->arr[i];
	}
	free(strings->arr);
	strings->arr = copy_strings;
	(strings->len)++;
}

void delete(strArr* strings){
	int current_length = len(strings);
	unsigned int del_ele;
	printf("Enter the index of the element to be deleted: ");
	scanf("%u", &del_ele);

	char ** copy_strings = calloc(current_length -1, sizeof(char *));
	for (int i=0; i< current_length-1; i++){
		copy_strings[i] = calloc(MAX_LEN, sizeof(char));
	}
	int i=0, j=0;
	while (j<current_length && i<current_length-1){
		printf("%d %d", i,j);
		if (j==del_ele){
			j++;
		}	
		else{
			copy_strings[i] = strings->arr[j];
			j++;
			i++;
		}
	}


	free(strings->arr);
	strings->arr = copy_strings;
	(strings->len)--;
}


int main(void){

	unsigned int initial_length;

	printf("Enter the length of the array: ");
	scanf("%u", &initial_length);

	strArr* strings = malloc(sizeof(strArr));

	strings->arr =  calloc(initial_length, sizeof(char *));
	strings->len= initial_length;
	for (int i=0; i< initial_length; i++){
		strings->arr[i] = calloc(MAX_LEN, sizeof(char));
	}

	for (int i=0; i<initial_length; i++){
		printf("Enter the string: ");
		scanf("%s", strings->arr[i]);
	}
	bool flag = true;
	while (flag){
		int input = -1;
		printf("%s", menu);
		scanf("%d", &input);
		if (input ==0) flag=false;
		else if (input >=1 && input<=5){
			switch (input){
				case 1: append(strings); break;
				case 2: prepend(strings); break;
				case 3: delete(strings); break;
				case 4: printf("%d\n", len(strings)); break;
				case 5: print(strings); break;
			}
		}else{
			printf("Enter a valid input (0-5)\n");
		}
		input = -1;
	}
					
	printf("Exiting have a nice day!\n");
}
