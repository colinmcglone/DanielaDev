#include <stdio.h>
#include <stdlib.h>

struct cell {
  int value;
  struct cell *prev;
  struct cell *next;
};

struct dll {
  struct cell *first;
};

//Initialize cell
struct cell *init(int v) {
  struct cell *new;
  new = malloc (sizeof(struct cell));
  new->value = v;
  new->prev = NULL;
  new->next = NULL;

  return new;
}

//Insert new cell to list
struct cell *insert(int v, struct cell *p, struct cell *n) {
  struct cell *new = init(v);
  new->prev = p;
  new->next = n;

  if(p != NULL) {
    p->next = new;
  }
  if(n != NULL) {
    n->prev = new;
  }
  return new;
}

//Delete cell
void del(struct cell *c) {
  struct cell *p = c->prev;
  struct cell *n = c->next;

  n->prev = p;
  p->next = n;

  c->value = 0;
  c->prev = NULL;
  c->next = NULL;

  free(c);
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
  struct cell *test = init(5);
  struct cell *dave = insert(7, test, NULL);
  struct cell *vic = insert(3, test, dave);

  del(dave);

  walk(test);

  free(test);
  free(dave);
  free(vic);

  return 0;
}
