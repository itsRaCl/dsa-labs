#include "person.h"
#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

person newPerson(int id, char* name, int age, int height, int weight){
	person x;
	x.id = id;
	x.name = name;
	x.age = age;
	x.weight = weight;
	x.height = height;

	return x;
}

int main(int argc, char** argv){
	if (argc==1 || argc >3){
		printf("Invalid Arguments");
	}
	int n = atoi(argv[2]);
	FILE* fptr = fopen(argv[1], "r");
	person* data = (person*) calloc(n, sizeof(person));
	for (int i=0; i<n;i++){
		int id, age, height, weight;
		char* name = (char*) malloc(100);
		fscanf(fptr, "%d,%[^,],%d,%d,%d\n", &id, name, &age, &height, &weight);
		data[i] = newPerson(id, name, age, height, weight);
	}
	printf("completing data insertion\n");
	insertionSort(data, n);
	for (int i =0; i<n; i++){
		printf("%d %s %d %d %d\n", data[i].id, data[i].name, data[i].age, data[i].height, data[i].weight);
	}
}
