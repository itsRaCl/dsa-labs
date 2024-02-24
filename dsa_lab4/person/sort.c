#include "sort.h"
#include "person.h"

void insertionSort(person *A, int n){
	for (int j=1; j<n; j++){
		insertInOrder(A[j], A, j);
	}
}

void insertInOrder(person v, person* A, int last){
	int j = last -1;

	while(j>=0 && v.weight<A[j].weight){
		A[j+1] = A[j];
		j--;
	}
	A[j+1] = v;
}
