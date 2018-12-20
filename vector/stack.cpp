#include <iostream>
#include <vector>

using namespace std;

void printStack(const vector<int> &stack) {
  cout << "(cap=" << stack.capacity() << ", len=" << stack.size() << ") ";

  for (const auto &element : stack)
    cout << element << ' ';

  cout << endl;
}

int main() {
  // push_back() pushes an element on the stack.
  // back() returns the value of the top element on the stack.
  // pop_back() pops an element off the stack.

  vector<int> stack;
  //stack.reserve(5);
  printStack(stack);

  stack.push_back(5);
  printStack(stack);

  stack.push_back(3);
  printStack(stack);

  stack.push_back(2);
  printStack(stack);

  cout << "top: " << stack.back() << '\n';

  stack.pop_back();
  printStack(stack);

  stack.pop_back();
  printStack(stack);

  stack.pop_back();
  printStack(stack);
}
