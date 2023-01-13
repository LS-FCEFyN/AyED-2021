#include "nary-tree.h"
#include "queue.h"
#include <stdlib.h>

static void bfs(struct nary_tree *);

static void insert(struct nary_tree *, void *);
static void remove(struct nary_tree *, struct nary_tree_node *);

static struct nary_tree_node *bfsSearch(struct nary_tree *, void *);
static struct nary_tree_node *findMinimum(struct nary_tree *);
static struct nary_tree_node *findMaximum(struct nary_tree *);

static int findNodeHeight(struct nary_tree *, struct nary_tree_node *);
static int findNodeDepth(struct nary_tree *, struct nary_tree_node *);

static void balanceTree(struct nary_tree *);

struct nary_tree *initialize_nary_tree(int numberOfChildren) {
  struct nary_tree *temp = malloc(sizeof(struct nary_tree));
  temp->root = (void *)0;
  temp->insert = &insert;
  temp->remove = &remove;
  temp->bfsSearch = &bfsSearch;
  temp->findMinimum = &findMinimum;
  temp->findMaximum = &findMaximum;
  temp->findNodeHeight = &findNodeHeight;
  temp->findNodeDepth = &findNodeDepth;
  temp->balanceTree = &balanceTree;
  temp->numOfChildrenPerLevel = numberOfChildren;
  return temp;
};

static struct nary_tree_node *initialize_nary_tree_node(void *data) {
  struct nary_tree_node *temp = malloc(sizeof(struct nary_tree_node));
  temp->data = data;
  temp->currentChildrenOnLevel = 0;
  temp->children = (void *)0;
  return temp;
}

static void addChildren(struct nary_tree_node *self, void *data) {
  if (self->children == (void *)0) {
    self->children = malloc(sizeof(struct nary_tree_node *));
    self->children[0] = initialize_nary_tree_node(data);
    self->currentChildrenOnLevel++;
  } else {
    void *temp =
        realloc(self->children, sizeof(struct nary_tree_node *) *
                                    (1 + (int)self->currentChildrenOnLevel));
    if (temp != (void *)0) {
      self->children = temp;
      self->children[self->currentChildrenOnLevel] =
          initialize_nary_tree_node(data);
      self->currentChildrenOnLevel++;
    } else {
      free(self->children);
      exit(EXIT_FAILURE);
    }
  }
}

static void insert(struct nary_tree *self, void *data) {
  if (self->root == (void *)0) {
    struct nary_tree_node *temp = initialize_nary_tree_node(data);
    self->root = temp;
  } else {
    struct nary_tree_node *current = self->root;
    if (current->currentChildrenOnLevel < self->numOfChildrenPerLevel) {
      addChildren(current, data);
    } else {
      struct queue *temp = initialize_queue();
      while (current->children != (void *)0) {
        for (int i = 0; i < self->numOfChildrenPerLevel; i++) {
          temp->enqueue(temp, current->children[0]);
        }
        current = temp->front(temp);
        temp->dequeue(temp);
      }
      temp->clear(temp);
      free(temp);
      addChildren(current, data);
    }
  }
}

static void remove(struct nary_tree *self, struct nary_tree_node *node) {}

static struct nary_tree_node *bfsSearch(struct nary_tree *self, void *data) {
  return (void *)0;
}

static struct nary_tree_node *findMinimum(struct nary_tree *self) {
  return (void *)0;
}
static struct nary_tree_node *findMaximum(struct nary_tree *self) {
  return (void *)0;
}

static int findNodeHeight(struct nary_tree *self, struct nary_tree_node *node) {
  return 0;
}
static int findNodeDepth(struct nary_tree *self, struct nary_tree_node *node) {
  return 0;
}

static void balanceTree(struct nary_tree *self) {}