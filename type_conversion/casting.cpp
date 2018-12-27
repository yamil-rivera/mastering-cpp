#include <iostream>

using namespace std;

int main() {
  float f = 10 / 4;
  cout << f << '\n';

  // C-style casts
  int i1 = 10;
  int i2 = 4;
  float f1 = (float)i1 / i2;
  cout << f1 << '\n';

  // static_cast
  // compile-time type checking
  float f2 = static_cast<float>(i1) / i2;
  cout << f2 << '\n';

  int i = 97;
  char ch = i; // implicit conversion
  //char ch = static_cast<char>(i);
  cout << ch << '\n';

  i = i / 2.5;
  //i = static_cast<int>(i / 2.5);
  cout << i;
}
