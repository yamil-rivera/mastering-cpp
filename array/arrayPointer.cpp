#include <iostream>

void passArray(int prime[5]) {
  // changing it here will change the original argument!
  prime[0] = 11;
  prime[1] = 7;
  prime[2] = 5;
  prime[3] = 3;
  prime[4] = 2;
}

void printSize(int array[]) {
  // prints the size of a pointer, not the size of the array!
  std::cout << sizeof(array) << '\n';
}

int main() {
  int array[5] = {9, 7, 5, 3, 1};

  // variable array contains the address of the first element of the array
  std::cout << "The array has address: " << array << '\n';
  std::cout << "Element 0 has address: " << &array[0] << '\n';
  std::cout << "First element value: " << *array << '\n';
  std::cout << "Second element address: " << array + 1 << " " << &array[1] << '\n';
  std::cout << "Second element value: " << *(array + 1) << '\n';

  // passing arrays to functions
  int prime[5] = {2, 3, 5, 7, 11};
  std::cout << "before passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " "
            << prime[4] << "\n";
  passArray(prime);
  std::cout << "after passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " "
            << prime[4] << "\n";

  // sizeof inside function
  std::cout << sizeof(prime) << '\n';
  printSize(prime);
}
