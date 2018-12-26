#include <iostream>

using namespace std;

class Divider {
  public:
    static int divide(int a, int b) {
      return a/b;
    }
};

int sum(int a, int b) {
  cout << "Int sum" << endl;
  return a + b;
}

float sum(float a, float b) {
  cout << "Float sum" << endl;
  return a + b;
}

char sum(char a, char b) {
  cout << "Char sum" << endl;
  return a + b;
}

int main() {
  cout << sum(1, 1) << endl;
  cout << sum(1.3f, 1.8f) << endl;
  cout << sum('4', '2') << endl;

  return 0;
}

