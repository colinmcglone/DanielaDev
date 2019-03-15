#include <stdio.h>
#include <stdlib.h>

int fib(int i) {
  int a[i+1];
  a[0] = 1;
  a[1] = 1;

  for(int j = 2; j <= i; j++) {
    a[j] = a[j-1] + a[j-2];
  }

  return a[i];
}

int main() {
  int i;
  printf("Enter a positive integer:\n");
  scanf("%d", &i);

  printf("f(%d) = %d\n", i, fib(i));
  return 0;

}
