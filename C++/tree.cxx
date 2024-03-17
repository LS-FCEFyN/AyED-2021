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

template <typename T, int Arity>
void Tree<T, Arity>::remove(T data)
{
    if (root == nullptr)
        return;
    std::shared_ptr<Node> currentNode = root;
    std::shared_ptr<Node> parentNode = nullptr;
    while (currentNode != nullptr && currentNode->data != data)
    {
        parentNode = currentNode;
        currentNode = currentNode->children[0];
    }

    if (currentNode == nullptr)
        return;

    if (currentNode->children.empty())
    {
        if (parentNode != nullptr)
        {
            parentNode->children.erase(std::remove(parentNode->children.begin(), parentNode->children.end(), currentNode), parentNode->children.end());
        }
        else
        {
            root.reset();
        }
    }
    else
    {
        if (parentNode != nullptr)
        {
            auto it = std::find(parentNode->children.begin(), parentNode->children.end(), currentNode);
            if (it != parentNode->children.end())
            {
                *it = currentNode->children[0];
                currentNode->children.erase(currentNode->children.begin());
            }
        }
        else
        {
            root = currentNode->children[0];
            currentNode->children.erase(currentNode->children.begin());
        }
    }
}

template <typename T, int Arity>
T &Tree<T, Arity>::bfs(T data)
{
    if (root == nullptr)
        return data;

    Queue<std::shared_ptr<Node>> queue;
    queue.enqueue(root);

    while (!queue.isEmpty())
    {
        std::shared_ptr<Node> currentNode = queue.dequeue();
        if (currentNode->data == data)
        {
            return currentNode->data;
        }
        for (const auto &child : currentNode->children)
        {
            queue.enqueue(child);
        }
    }

    return data;
}

template <typename T, int Arity>
T &Tree<T, Arity>::dfs(T data)
{
    if (root == nullptr)
        return data;

    std::stack<std::shared_ptr<Node>> stack;
    stack.push(root);

    while (!stack.empty())
    {
        std::shared_ptr<Node> currentNode = stack.top();
        stack.pop();
        if (currentNode->data == data)
        {
            return currentNode->data;
        }
        for (const auto &child : currentNode->children)
        {
            stack.push(child);
        }
    }

    return data;
}

template <typename T, int Arity>
void Tree<T, Arity>::clear()
{
    root.reset();
}
