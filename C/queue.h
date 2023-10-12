#ifndef QUEUE_H
#define QUEUE_H

struct queue_node {
  void *data;
  struct queue_node *next;
};

struct queue {
  struct queue_node *head;
  struct queue_node *rear;
  void (*enqueue)(struct queue *self, void *data);
  void (*dequeue)(struct queue *self);
  void *(*front)(struct queue *self);
  void (*clear)(struct queue *self);
  int (*isEmpty)(struct queue *self);
};

struct queue *initialize_queue(void);

#endif
