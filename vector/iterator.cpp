#include <iostream>
#include <vector>

using namespace std;

int main() {
  // iterator & const_iterator (read-only)

  vector<int> vect;
  for (int count = 0; count < 6; ++count)
    vect.push_back(count);

  vector<int>::const_iterator it;
  it = vect.begin(); // assign it to the start of the vector
  while (it != vect.end()) {
    cout << *it << " ";
    ++it;
  }

  cout << '\n';
}
