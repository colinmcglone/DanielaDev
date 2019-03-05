#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
  int stuff;
  struct node *forward, *backward;
};

struct node *initial(int s) {
  struct node *i = (struct node *)malloc(sizeof(struct node));
  i->stuff = s;
  i->forward = NULL;
  i->backward = NULL;
  return i;
}

struct node *insert_first(struct node *old_first, int s) {
  struct node *first = (struct node *)malloc(sizeof(struct node));
  first->stuff = s;
  first->backward = NULL;
  first->forward = old_first;
  old_first->backward = first;
    return first;
}

struct node *insert_last(struct node *old_last, int s) {
  struct node *last = (struct node *)malloc(sizeof(struct node));
  last->stuff = s;
  last->backward = old_last;
  last->forward = NULL;
  old_last->forward = last;
    return last;
}

struct node *insert_middle(struct node *before, struct node *after, int s) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->stuff = s;
  new_node->backward = before;
  new_node->forward = after;
  before->forward = new_node;
  after->backward = new_node;
    return new_node;
}

void print_list(struct node *first) {
  struct node *current_node = first;
  printf("\n The first node is %i \n", current_node->stuff);
  while (current_node->forward != NULL) {
    current_node = current_node->forward;
    printf(" The next node is %i \n", current_node->stuff);
  }
}

void print_reverse(struct node *last) {
  struct node *current_node = last;
  printf("\n The last node is %i \n", current_node->stuff);
  while (current_node->backward != NULL) {
    current_node = current_node->backward;
    printf(" The previous node is %i \n", current_node->stuff);
  }
}

bool search_list(struct node *first, int value) {
  struct node *current_node = first;
  while (current_node->forward != NULL) {
    current_node = current_node->forward;
    if (current_node->stuff == value) {
      printf("The value %i is in the linked list. \n", current_node->stuff);
      return true;
    }
  }
  printf("The value %i is not in the linked list. \n", value);
  return false;
}

void print_node(struct node *current) {
  struct node *current_node = current;
  printf("\n The current node is %i \n", current_node->stuff);
  if (current_node->backward != NULL) {
    printf(" The previous node is %i \n", current_node->backward->stuff);
  }
  if (current_node->forward != NULL) {
    printf(" The next node is %i \n", current_node->forward->stuff);
  }
}

//Currently only removes from the middle!!!
void del(struct node *current) {
  current->backward->forward = current->forward;
  current->forward->backward = current->backward;
}

int main() {
  struct node *first = (struct node *)malloc(sizeof(struct node));
  struct node *second = (struct node *)malloc(sizeof(struct node));
  struct node *third = (struct node *)malloc(sizeof(struct node));
  struct node *new_first = (struct node *)malloc(sizeof(struct node));
  struct node *middle = (struct node *)malloc(sizeof(struct node));
  first = initial(1);
  second = insert_last(first, 2);
  third = insert_last(second, 3);
  new_first = insert_first(first, 0);
  middle = insert_middle(first, second, 11);

  print_list(new_first);
  print_reverse(third);

  del(middle);
  print_list(new_first);

  search_list(new_first, 11);
  free(first);
  free(second);
  free(third);
  free(new_first);
  free(middle);
  return 0;
}
