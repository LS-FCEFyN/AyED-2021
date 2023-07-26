#ifndef STACK_H
#define STACK_H

struct stack_node {
  void *data;
  struct stack_node *next;
};

struct stack {
  struct stack_node *head;
  void (*push)(struct stack *self, void *data);
  void (*pop)(struct stack *self);
  void *(*peek)(struct stack *self);
  void (*clear)(struct stack *self);
  int (*isEmpty)(struct stack *self);
};

struct stack *initialize_stack();

#endif
