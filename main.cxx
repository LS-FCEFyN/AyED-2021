#include <iostream>
#include <string>

#include "stack.hxx"
#include "queue.hxx"

int main()
{

  Stack<int> s;

  // Test push and peek
  s.push(1);
  s.push(2);
  s.push(3);
  std::cout << "Top element: " << s.peek() << std::endl; // Should output 3

  // Test pop
  s.pop();
  std::cout << "Top element after pop: " << s.peek() << std::endl; // Should output 2

  // Test clear and isEmpty
  s.clear();
  std::cout << "Stack empty after clear: " << std::boolalpha << s.isEmpty() << std::endl; // Should output true

  Queue<int> q;

  // Test enqueue and front
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  std::cout << "Front element: " << q.front() << std::endl; // Should output 1

  // Test dequeue
  q.dequeue();
  std::cout << "Front element after dequeue: " << q.front() << std::endl; // Should output 2

  // Test clear and isEmpty
  q.clear();
  std::cout << "Queue empty after clear: " << std::boolalpha << q.isEmpty() << std::endl; // Should output true

  return 0;
}