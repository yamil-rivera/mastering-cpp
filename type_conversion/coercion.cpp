#include <iostream>
#include <climits>
#include <typeinfo>

using namespace std;

int main() {
  // numeric promotion
  // a value from one type is converted into a value of a larger similar data type
  long l(64); // integer -> long
  double d(0.12f); // float -> double

  // numeric conversion
  // convert a value from a larger type to a similar smaller type, or between different types
  int i = 3.5;
  cout << i << '\n';

  i = INT_MAX;
  cout << i << '\n';
  short s = i;
  cout << s << '\n';

  // evaluating arithmetic expressions
  short a(4);
  short b(5);
  cout << typeid(a + b).name() << " " << a + b << '\n';

  double d1(4.0);
  short s1(2);
  cout << typeid(d1 + s1).name() << " " << d1 + s1 << std::endl;
}
