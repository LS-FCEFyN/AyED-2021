#ifndef TREE_HXX
#define TREE_HXX

#include <memory>
#include <vector>

template <typename T, int Arity>
class Tree
{
public:
    Tree();
    void insert(T);
    void remove(T);
    T &bfs(T);
    T &dfs(T);
    void clear();

private:
    struct Node
    {
        T data;
        std::vector<std::shared_ptr<Node>> children;
        Node(T data, std::shared_ptr<Node> children = nullptr) : data(data), children(children) {}
    };
    std::shared_ptr<Node> root;
};

#include "tree.cxx"
#endif