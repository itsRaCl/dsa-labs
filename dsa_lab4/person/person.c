#include "person.h"
#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

person newPerson(int id, char* name, int age, int height, int weight){
	person x;
	x.id = id;
	x.name = name;
	x.age = age;
	x.weight = weight;
	x.height = height;

	return x;
}

int main(){
	person* data = (person*) calloc(5, sizeof(person));
	data[0] = newPerson(1, "Sokka", 15, 150, 45);
	data[1] = newPerson(2, "Aang", 112, 137, 35);
	data[2] = newPerson(3, "Zuko", 16, 160, 50);
	data[3] = newPerson(4, "Katara", 14, 145, 38);
	data[4] = newPerson(5, "Toph", 12, 113, 30);
	
	insertionSort(data, 5);

	for (int i =0; i<5; i++){
		printf("%d %s %d %d %d\n", data[i].id, data[i].name, data[i].age, data[i].height, data[i].weight);
	}
}
