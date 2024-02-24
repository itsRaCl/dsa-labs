#include <stdio.h>
#include <sys/time.h>

void fibonacciIter(int n) {
  unsigned long long prev = 0, prev_prev = 1;
  for (int i = 0; i < n; i++) {
    unsigned long long temp = prev;
    prev = prev_prev + prev;
    prev_prev = temp;
  }
}

void fibonacciRecursive(unsigned long long prev, unsigned long long prev_prev,
                        int n) {
  if (n == 0) {
    return;
  }
  fibonacciRecursive(prev + prev_prev, prev, --n);
}

int main() {
  struct timeval t1, t2;
  gettimeofday(&t1, NULL);
  fibonacciRecursive(0, 1, 90);
  gettimeofday(&t2, NULL);
  double time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
  time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;

  printf("%f\n", time_taken);
  gettimeofday(&t1, NULL);
  fibonacciIter(90);
  gettimeofday(&t2, NULL);
  time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
  time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
  printf("%f\n", time_taken);
  return 0;
}
