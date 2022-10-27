#ifndef STACK_H
#define STACK_H

struct stack_node
{
  void *data;
  struct stack_node *next;
};

struct stack
{
  struct stack_node *head;
  void (*push) (struct stack * self, void *data);
  void (*pop) (struct stack * self);
  void *(*peek) (struct stack * self);
  void (*clear) (struct stack * self);
  int (*isEmpty) (struct stack * self);
};

struct stack *initialize_stack ();
static struct stack_node *initialize_stack_node (void *data);
static void push (struct stack *, void *);
static void pop (struct stack *);
static void *peek (struct stack *);
static void clear (struct stack *);
static int isEmpty (struct stack *);

#endif
