#include "nary-tree.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

static void bfs(struct nary_tree *);

static void insert(struct nary_tree *, void *);
static void removeNode(struct nary_tree *, struct nary_tree_node *);

static struct nary_tree_node *bfsSearch(struct nary_tree *, void *);
static struct nary_tree_node *findMinimum(struct nary_tree *);
static struct nary_tree_node *findMaximum(struct nary_tree *);

static int findNodeHeight(struct nary_tree *, struct nary_tree_node *);
static int findNodeDepth(struct nary_tree *, struct nary_tree_node *);

static void balanceTree(struct nary_tree *);

static void printTree(struct nary_tree *, struct nary_tree_node *, int);

static void free_nary_tree_node(struct nary_tree_node *);

static void free_nary_tree(struct nary_tree *);

struct nary_tree *initialize_nary_tree(int numberOfChildren) {
  struct nary_tree *temp = malloc(sizeof(struct nary_tree));
  temp->root = (void *)0;
  temp->insert = &insert;
  temp->remove = &removeNode;
  temp->bfsSearch = &bfsSearch;
  temp->findMinimum = &findMinimum;
  temp->findMaximum = &findMaximum;
  temp->findNodeHeight = &findNodeHeight;
  temp->findNodeDepth = &findNodeDepth;
  temp->balanceTree = &balanceTree;
  temp->print = &printTree;
  temp->clear = &free_nary_tree;
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
    struct queue *q = initialize_queue();
    q->enqueue(q, self->root);
    int currentLevel = 0;
    int nextLevel = 0;
    while (!q->isEmpty(q)) {
      struct nary_tree_node *current = q->front(q);
      q->dequeue(q);
      currentLevel--;
      if (current->currentChildrenOnLevel < self->numOfChildrenPerLevel) {
        addChildren(current, data);
        break;
      }
      for (int i = 0; i < self->numOfChildrenPerLevel; i++) {
        if (current->children[i] != (void *)0) {
          q->enqueue(q, current->children[i]);
          nextLevel++;
        }
      }
      if (currentLevel == 0) {
        currentLevel = nextLevel;
        nextLevel = 0;
      }
    }
    q->clear(q);
    free(q);
  }
}

static void removeNode(struct nary_tree *self, struct nary_tree_node *node) {}

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

void printTree(struct nary_tree *tree, struct nary_tree_node *node, int level) {
  if (node == NULL) {
    return;
  }
  printf("|");
  for (int i = 0; i < level; i++) {
    printf("---|");
  }
  printf(" %s\n", (char *)node->data);

  for (int i = 0; i < node->currentChildrenOnLevel; i++) {
    printTree(tree, node->children[i], level + 1);
  }
}

void free_nary_tree_node(struct nary_tree_node *node) {
  if (node == NULL) {
    return;
  }
  for (int i = 0; i < node->currentChildrenOnLevel; i++) {
    free_nary_tree_node(node->children[i]);
  }
  free(node->children);
  free(node);
}

void free_nary_tree(struct nary_tree *tree) { free_nary_tree_node(tree->root); }