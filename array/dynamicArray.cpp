#include <iostream>

int main() {
  std::cout << "Enter a positive integer: ";
  int length;
  std::cin >> length;

  int *array = new int[length];

  std::cout << "I just allocated an array of integers of length " << length << '\n';

  array[0] = 5; // set element 0 to value 5

  delete[] array;

  // resize?
  // dynamically allocating a new array, copying the elements over, and deleting the old array

  // ~~> std::vector
}
