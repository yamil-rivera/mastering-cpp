#include <iostream>
#include <array>

void printLength(const std::array<int, 5> &myArray) {
  std::cout << "length inside fn: " << myArray.size() << '\n';
}

int main() {
  std::array<int, 5> myArray = {9, 7, 5, 3, 1};
  std::cout << myArray[1] << '\n';
  myArray[2] = 6;

  // bounds checking
  myArray.at(1) = 6;
  //myArray.at(9) = 10; // throw error

  // pass to fn
  std::cout << "length: " << myArray.size() << '\n';
  printLength(myArray);

  for (const int &element : myArray)
    std::cout << element << ' ';
}
