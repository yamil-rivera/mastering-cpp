#include <iostream>
#include <vector>

using namespace std;

int main() {
  // dynamic array
  vector<int> array = {9, 7, 5, 3, 1};

  // the memory will be deallocated as soon as array goes out of scope. This makes std::vector much safer to use than doing your own memory allocation.

  cout << "The length is: " << array.size() << '\n';
  cout << "The address of vector: " << &array << '\n';
  cout << "The address of first element: " << &array[0] << '\n';
  cout << "The address of second element: " << &array[1] << '\n';

  //cout << array[6] << '\n'; // no bounds checking
  //cout << array.at(6) << '\n'; // does bounds checking

  array.resize(3);
  cout << "The length is: " << array.size() << '\n';

  for (auto const &element: array)
    cout << element << ' ';

  cout << '\n';

  array.resize(5);
  cout << "The length is: " << array.size() << '\n';

  for (auto const &element: array)
    cout << element << ' ';
}

// https://en.cppreference.com/w/cpp/container/vector
