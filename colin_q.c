#include <stdio.h>
#include <stdlib.h>

struct item {
  int value;
  struct item *next;
};

struct queue {
  struct item *first;
  struct item *last;
  int size;
};

//Initialize item
struct item *init_item(int v) {
  struct item *new;
  new = malloc (sizeof(struct item));
  new->value = v;
  new->next = NULL;

  return new;
}

//Initialize queue
struct queue *init_queue(struct item *n) {
  struct queue *new;
  new = malloc (sizeof(struct queue));
  new->first = n;
  new->last = n;
  new->size = 1;

  return new;
}

//Add to end of queue
struct queue *enqueue(int v, struct queue *s) {
  struct item *new = init_item(v);
  s->last->next = new;
  s->last = new;
  s->size += 1;

  return s;
}

//Remove fist item in queue
struct queue *dequque(struct queue *s) {
  if(s->first == s->last) {
    free(s->first);
    s->size = 0;
  }
  struct item *n;
  n = s->first;
  s->first = n->next;
  s->size -= 1;

  free(n);

  return s;
}

//Print entire queue
void walk(struct queue *s) {
  struct item *cur = s->first;
  //Iterate through queue, print values
  printf("%d\n", cur->value);
  while(cur->next != NULL) {
    cur = cur->next;
    printf("%d\n", cur->value);
  }
}

int main() {
  struct item *a = init_item(1);
  struct queue *st = init_queue(a);
  enqueue(2, st);
  enqueue(3, st);

  printf("Queue Size: %d\n", st->size);
  walk(st);

  return 0;
}
