#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

struct stack {
  struct node *head;
  int size;
};

//Initialize node
struct node *init_node(int v) {
  struct node *new;
  new = malloc (sizeof(struct node));
  new->value = v;
  new->next = NULL;

  return new;
}

//Initialize stack
struct stack *init_stack(struct node *n) {
  struct stack *new;
  new = malloc (sizeof(struct stack));
  new->head = n;
  new->size = 1;

  return new;
}

//Add to beginning of stack
struct stack *push(int v, struct stack *s) {
  struct node *new = init_node(v);
  new->next = s->head;
  s->head = new;
  s->size += 1;

  return s;
}

//Remove fist item in stack
struct stack *pop(struct stack *s) {
  struct node *n;
  n = s->head;
  s->head = n->next;
  s->size -= 1;

  return s;
}

//Print entire stack
void walk(struct stack *s) {
  struct node *cur = s->head;
  //Iterate through stack, print values
  printf("%d\n", cur->value);
  while(cur->next != NULL) {
    cur = cur->next;
    printf("%d\n", cur->value);
  }
}

int fib(int i) {
  struct node *n = init_node(1);
  struct stack *s = init_stack(n);
  push(1, s);

  int e = 0;
  while(e < i-1) {
    int first = s->head->value;
    pop(s);
    int second = s->head->value;
    pop(s);

    push(first, s);
    push(first+second, s);

    e++;
  }

  return s->head->value;
}

int main() {
  int i;
  while(1==1) {
    printf("Enter a positive integer:\n");
    scanf("%d", &i);

    printf("f(%d) = %d\n", i, fib(i));
  }

  return 0;
}
