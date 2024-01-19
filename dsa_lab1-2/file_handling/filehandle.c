#include <stdio.h>
#include <strings.h>

int main(){
	FILE *fptr = fopen(__FILE__, "r");
	char line[100000];
	while (fgets(line, 10000, fptr)){
		printf("%s\n", line);
	}
	fclose(fptr);
}
