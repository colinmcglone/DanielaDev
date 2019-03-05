#include <stdio.h>

struct cell {
  int value;
  struct cell *prev;
  struct cell *next;
};

struct dll {
  struct cell *first;
};


struct cell insert(int v, struct cell *p, struct cell *n) {
  struct cell new = {v, p, n};
  printf("\nPrev: %p\n", new.prev);
  printf("\nValue: %d\n", new.value);
  printf("\nNext: %p\n", new.next);
  printf("\nNew: %p\n", &new);
  printf("=============\n");

  if(p != NULL) {

    //*p->next = new;
    //printf("\nNew: %p\n", &new);
    printf("\nPNext: %p\n", p->next);
  }
  if(n != NULL) {
    //*n->prev = new;
    printf("\nPPrev: %p\n", p->next);
  }
  return new;
}

void walk(struct cell *c) {
  //Go to root of list
  int i = 1;
  struct cell *cur = c;
  while(i==1) {
    if(cur->prev == NULL) {
      i = 0;
    }
    else {
      cur = cur->prev;
    }
  }
  int e = 0;
  while(e == 0) {
    printf("\nPrev: %p\n", cur->prev);
    printf("\nValue: %d\n", cur->value);
    printf("\nNext: %p\n", cur->next);
    printf("=============\n");
    if(cur->next == NULL) {
      e = 1;
    }
    else {
      cur = cur->next;
    }
  }
}
int main() {
  struct cell test = {2, NULL, NULL};
  struct cell dave = insert(5, &test, NULL);
}
