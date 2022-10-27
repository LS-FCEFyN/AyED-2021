#include "stack.h"
#include <stdlib.h>

static int
isEmpty (struct stack *self)
{
  return self->head == (void *) 0;
}

static void
push (struct stack *self, void *data)
{
  struct stack_node *temp = initialize_stack_node (data);
  if (self->head == (void *) 0)
    {
      self->head = temp;
    }
  else
    {
      temp->next = self->head;
      self->head = temp;
    }
}

static void
pop (struct stack *self)
{
  struct stack_node *temp = self->head;
  if (self->head == (void *) 0)
    {
      return;
    }
  self->head = temp->next;
  free (temp);
}

static void *
peek (struct stack *self)
{
  if (self->head != (void *) 0)
    return self->head->data;
  exit (EXIT_FAILURE);
}

static void
clear (struct stack *self)
{
  struct stack_node *tmp = (void *) 0;
  while (self->head != (void *) 0)
    {
      tmp = self->head;
      self->head = self->head->next;
      free (tmp);
    }
}

struct stack *
initialize_stack ()
{
  struct stack *temp = (struct stack *) malloc (sizeof (struct stack));
  temp->head = (void *) 0;
  temp->isEmpty = &isEmpty;
  temp->push = &push;
  temp->pop = &pop;
  temp->peek = &peek;
  temp->clear = &clear;
  return temp;
}

static struct stack_node *
initialize_stack_node (void *data)
{
  struct stack_node *temp =
    (struct stack_node *) malloc (sizeof (struct stack_node));
  temp->next = (void *) 0;
  temp->data = (void *) 0;
  temp->data = data;
  return temp;
}
