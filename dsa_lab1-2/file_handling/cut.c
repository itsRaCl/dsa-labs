#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int main(){
	FILE *text1 = fopen("text1.txt", "r");
	FILE *text2 = fopen("text2.txt", "w");
	char line[10000];
	while (fgets(line, 10000, text1)){
		fprintf(text2, "%s", line);
	}
	fclose(text2);
	fclose(text1);
	FILE *text3 = fopen("text1.txt", "w");
	fclose(text3);
	return 0;
}
