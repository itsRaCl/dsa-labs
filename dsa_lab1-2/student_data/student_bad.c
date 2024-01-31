#include "student.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/time.h>

int main() {
  FILE *f = fopen("data.txt", "r");
  char line[10000];
  student **arr = calloc(10000, sizeof(student *));
  while (fgets(line, 10000, f)) {
    bool comma_flag = false;
    int i = 0;
    int j = 0;
    char id[10000];
    char cgpa[10000];
    student *stud = calloc(1, sizeof(student));
    while (line[i] != '\n') {
      if (comma_flag) {
        cgpa[j] = line[i];
        j++;
      } else {
        if (line[i] != ',') {
          id[j] = line[i];
          j++;
        } else {
          id[j] = '\0';
          stud->id = id;
          comma_flag = true;
          j = 0;
        }
      }
      i++;
    }
    cgpa[j] = '\0';
    stud->cgpa = atof(cgpa);

    printf("%s, %f\n", stud->id, stud->cgpa);
  }
  return 0;
}
