#include <stdio.h>
#include <stdlib.h>
#include "intMerge.h"
#include <strings.h>

void mergeSort(int A[], int st, int en){
	if (en -st <1) return;

	int mid = (st + en)/2;

	mergeSort(A, st, mid);
	mergeSort(A,mid+1, en);
	merge(A, st, mid,en);
}

int main(int argc, char** argv){
	if (argc==1 || argc >3){
		printf("Invalid Arguments");
	}
	int n = atoi(argv[2]);
	FILE* fptr = fopen(argv[1], "r");
	int* data = (int*) calloc(n, sizeof(int));
	for (int i=0; i<n;i++){
		int balance;
		fscanf(fptr, "%d", &balance);
		data[i]=balance;
	}
	mergeSort(data, 0, n-1);

	for (int i=0; i<n; i++){
		printf("%d\n", data[i]);
	}
}
