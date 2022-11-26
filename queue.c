#include "queue.h"
#include <stdlib.h>

static struct queue_node *initialize_queue_node (void *);
static void enqueue (struct queue *, void *);
static void dequeue (struct queue *);
static void *front (struct queue *);
static void clear (struct queue *);
static int isEmpty (struct queue *);

static int
isEmpty (struct queue *self)
{
  return self->head == (void *) 0;
}

static void
enqueue (struct queue *self, void *data)
{
  struct queue_node *tmp = initialize_queue_node (data);
  if (self->head == (void *) 0)
    {
      self->head = self->rear = tmp;
    }
  else
    {
      self->rear->next = tmp;
      self->rear = tmp;
    }
}

static void
dequeue (struct queue *self)
{
  struct queue_node *tmp = self->head;
  if (self->head == (void *) 0)
    {
      exit (EXIT_FAILURE);
    }
  if (self->head == self->rear)
    {
      self->head = self->rear = (void *) 0;
    }
  else
    {
      self->head = self->head->next;
    }
  free (tmp);
}

static void *
front (struct queue *self)
{
  if (self->head != (void *) 0)
    {
      return self->head->data;
    }
  exit (EXIT_FAILURE);
}

static void
clear (struct queue *self)
{
  while (self->head != (void *) 0)
    {
      dequeue (self);
    }
}

struct queue *
initialize_queue (void)
{
  struct queue *tmp = malloc (sizeof (struct queue));
  tmp->head = (void *) 0;
  tmp->rear = (void *) 0;
  tmp->isEmpty = &isEmpty;
  tmp->enqueue = &enqueue;
  tmp->dequeue = &dequeue;
  tmp->clear = &clear;
  tmp->front = &front;
  return tmp;
}

static struct queue_node *
initialize_queue_node (void *data)
{
  struct queue_node *tmp = malloc (sizeof (struct queue_node));
  tmp->data = data;
  tmp->next = (void *) 0;
  return tmp;
}
