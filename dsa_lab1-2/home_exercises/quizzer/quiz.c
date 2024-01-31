#include <stdio.h>

#include "set.h"

int main(void){
	char provided_answers[10];

	printf("N stands for unattempted\n");
	for (int i=0; i<10;i++){
		char inpt  = ' ';
		bool flag = false;
		while (!flag){
			printf("Enter your answer for question %d (A/B/C/D/N) ==> ", i+1);
			scanf(" %c", &inpt);
			
			if (inpt == 'A' || inpt == 'B' || inpt == 'C' || inpt == 'D' || inpt == 'N'){
				flag = true;
			}else{
				printf("Invalid response, enter out of A, B, C, D, N (not attempted)\n");
			}
		}
		provided_answers[i] = inpt;
		inpt = ' ';
	}

	int score = answer_checker(provided_answers);

	printf("You have scored: %d/40\n", score);
}

