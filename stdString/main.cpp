#include <iostream>
//#include <string>

using namespace std;

int main() {
  string s = "0123456789";
  cout << "Length: " << s.length() << endl;
  cout << "Capacity: " << s.capacity() << endl;

  s += "abcdef";
  cout << "Length: " << s.length() << endl;
  cout << "Capacity: " << s.capacity() << endl;

  //s.append(" other string");
  //cout << s << endl;

  //s.insert(16, "cccc");
  //cout << s << endl;
}

// https://en.cppreference.com/w/cpp/string/basic_string
