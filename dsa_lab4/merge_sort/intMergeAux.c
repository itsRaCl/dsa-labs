#include "intMergeAux.h"

void mergeAux(int L1[], int s1, int e1, int L2[], int s2, int e2, int L3[], int s3, int e3){
	int i,j,k;

	i=s1, j=s2, k=s3;

	while (i<=e1 && j<=e2){
		if (L1[i] < L2[j]){
			L3[k++] = L1[i++];
		}else{
			L3[k++] = L2[j++];
		}
	}

	while (i<=e1){
		L3[k++] = L1[i++];
	}

	while (j<=e2){
		L3[k++] = L2[j++];
	}
}
