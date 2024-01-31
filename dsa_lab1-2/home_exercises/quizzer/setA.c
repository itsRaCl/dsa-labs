#include "set.h"

int answer_checker(char * given_answers){
	char answers[10] = {'A', 'C', 'B', 'D', 'C', 'D', 'B', 'A', 'C'};
	int score =0;
	for (int i=0; i<10;i++){
		if (given_answers[i] == answers[i]){
			score += CORRECT_SCORE;
		}else if (given_answers[i] == 'N'){
			score += UNATTEMPTED_SCORE;
		}else{
			score += INCORRECT_SCORE;
		}
	}

	if (score < 0) return 0;
	else return score;
}
