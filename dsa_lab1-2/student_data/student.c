#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/time.h>

struct timeval t1, t2;

void createArray(student *studentArray) {
  FILE *f = fopen("data.txt", "r");
  char line[10000];
  int i;
  while (fgets(line, 10000, f)) {
    char id[100];
    double cgpa;
    sscanf(line, "%[^,],%lf", id, &cgpa);
    studentArray[i].cgpa = cgpa;
    studentArray[i].id = id;
    i++;
  }
  fclose(f);
}

ll *createLL() {
  FILE *f = fopen("data.txt", "r");
  ll *studentData = (ll *)calloc(1, sizeof(ll));
  char line[10000];
  int i;
  studNode *prev_node;
  while (fgets(line, 10000, f)) {
    studNode *curr_node = (studNode *)malloc(sizeof(studNode));
    char id[100];
    double cgpa;
    sscanf(line, "%[^,],%lf", id, &cgpa);
    curr_node->student.id = id;
    curr_node->student.cgpa = cgpa;
    curr_node->next = NULL;
    if (studentData->count == 0) {
      studentData->head = curr_node;
      prev_node = studentData->head;
    } else {
      prev_node->next = curr_node;
      prev_node = curr_node;
    }
    studentData->count++;
  }
  fclose(f);
  return studentData;
}

int main() {
  student *studentArray = calloc(10000, sizeof(student));
  gettimeofday(&t1, NULL);
  createArray(studentArray);
  gettimeofday(&t2, NULL);

  double time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
  time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;

  printf("Array took %f seconds to execute\n", time_taken);

  gettimeofday(&t1, NULL);
  ll *studentLL = createLL();
  gettimeofday(&t2, NULL);
  time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
  time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
  printf("LL took %f seconds to execute\n", time_taken);
  studNode *temp = studentLL->head;
  return 0;
}
