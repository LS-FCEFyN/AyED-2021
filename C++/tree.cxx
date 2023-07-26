#include "tree.hxx"
#include "queue.hxx"
#include "stack.hxx"

template <typename T, int Arity>
Tree<T, Arity>::Tree() : root(nullptr){};

template <typename T, int Arity>
void Tree<T, Arity>::insert(T data)
{
    auto new_node = std::make_shared<Node>(data, children);
    if (root == nullptr)
    {
        root->data = data;
    }
    else
    {
        std::shared_ptr<Node> currentNode = root;
        int currentChildrenOnLevel = currentNode->children.size();

        if (currentChildrenOnLevel < Arity)
        {
            currentNode->children.push_back(std::make_shared<Node>(data));
        }
        else
        {
            Queue<std::shared_ptr<Node>> q;
            q.enqueue(currentNode);
            while (!q.isEmpty())
            {
                currentNode = q.front();
                q.dequeue();
                currentChildrenOnLevel = currentNode->children.size();

                if (currentChildrenOnLevel < Arity)
                {
                    currentNode->children.push_back(std::make_shared<Node>(data));
                    break;
                }

                for (const auto &child : currentNode->children)
                {
                    q.push(child);
                }
            }
        }
    }
}