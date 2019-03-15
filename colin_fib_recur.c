#include <stdio.h>
#include <stdlib.h>

int fib(int i) {
  if(i == 0 || i == 1) {
    return 1;
  }
  return fib(i-1) + fib(i-2);
}

int main() {
  int i;
  printf("Enter a positive integer:\n");
  scanf("%d", &i);

  printf("f(%d) = %d\n", i, fib(i));
  return 0;

}
