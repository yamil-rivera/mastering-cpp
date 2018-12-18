#include <iostream>

int main() {
  // init array
  int prime[5] = {2, 3, 5, 7, 11};

  // only initialize first 3 elements, the remaining elements are initialized to 0
  int a[5] = {7, 4, 5};
  std::cout << "First element value: " << a[0] << '\n';
  std::cout << "Fifth element value: " << a[4] << '\n';

  // initialize all elements to 0
  int b[5] = {};

  // omitted length
  int c[] = {0, 1, 2, 3, 4};

  // sizeof
  std::cout << "The size of the array: " << sizeof(c) << '\n';

  // length
  std::cout << "The array has: " << sizeof(c) / sizeof(c[0]) << " elements\n";

  // out of range
  std::cout << "Out of range value: " << c[100] << '\n';

  // stack overflow
  //int array[10000000];

  // multidimensional arrays
  int m[3][5] =
      {
          {1, 2, 3, 4, 5}, // row 0
          {6, 7, 8, 9, 10}, // row 1
          {11, 12, 13, 14, 15} // row 2
      };

  for (int row = 0; row < 3; ++row)
    for (int col = 0; col < 5; ++col)
      std::cout << m[row][col] << ' ';
}
