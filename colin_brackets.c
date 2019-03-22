#include <stdio.h>
#include <stdlib.h>

struct node {
  char value;
  struct node *next;
};

struct stack {
  struct node *head;
  int size;
};

//Initialize node
struct node *init_node(char v) {
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
struct stack *push(char v, struct stack *s) {
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

  free(n);

  return s;
}

//Print entire stack
void walk(struct stack *s) {
  struct node *cur = s->head;
  //Iterate through stack, print values
  printf("\n%c", cur->value);
  while(cur->next != NULL) {
    cur = cur->next;
    printf("%c", cur->value);
  }
  printf("\n");
}

int main() {
  char i;
  printf("Enter a Bracket:\n");
  getc(i);
  struct node *a = init_node(i);
  struct stack *st = init_stack(a);

  if(i == ')' || i == ']' || i == '}') {
    return 0;
  }

  int j = 1;
  while(j==1) {
    printf("Enter another Bracket:\n");
    getc(i);
    if(i == '(' || i == '[' || i == '{') {
      push(i, st);
    } else if(i == ')') {
      if(st->head == NULL) {
        j = 0;
      } else if(st->head->value == '(') {
        pop(st);
      } else {
        j = 0;
      }
    } else if(i == ']') {
      if(st->head == NULL) {
        j = 0;
      } else if(st->head->value == '[') {
        pop(st);
      } else {
        j = 0;
      }
    } else if(i == '}') {
      if(st->head == NULL) {
        j = 0;
      } else if(st->head->value == '{') {
        pop(st);
      } else {
        j = 0;
      }
    } else {
      j = 0;
    }
  }

  return 0;
}
