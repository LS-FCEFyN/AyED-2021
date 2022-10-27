#ifndef QUEUE_H
#define QUEUE_H

struct queue_node
{
  void *data;
  struct queue_node *next;
};

struct queue
{
  struct queue_node *head;
  struct queue_node *rear;
  void (*enqueue) (struct queue * self, void *data);
  void (*dequeue) (struct queue * self);
  void *(*front) (struct queue * self);
  void (*clear) (struct queue * self);
  int (*isEmpty) (struct queue * self);
};

struct queue *initialize_queue ();
static struct queue_node *initialize_queue_node (void *);
static void enqueue (struct queue *, void *);
static void dequeue (struct queue *);
static void *front (struct queue *);
static void clear (struct queue *);
static int isEmpty (struct queue *);

#endif
