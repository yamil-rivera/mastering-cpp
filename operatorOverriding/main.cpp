#include <iostream>

using namespace std;

class fake_vector_class {
  private:
    int* elem;
    int sz;
  public:
    fake_vector_class(int s) {
      sz = s;
      elem = new int[s];
    }

    fake_vector_class(const fake_vector_class& copy) {
      elem = new int[copy.sz];
      sz = copy.sz;

      for (int i = 0; i < sz; i +=1) {
        elem[i] = copy.elem[i];
      }
    }

    fake_vector_class& operator=(const fake_vector_class& copy) {
      delete[] elem;
      elem = new int[copy.sz];
      sz = copy.sz;

      for (int i = 0; i < sz; i += 1) {
        elem[i] = copy.elem[i];
      }

      return *this;
    }

    int size() { return sz; }

    int& operator[](int i) {
      if (i < sz) {
        return elem[i];
      }
      throw "Out of bounds!";
    }
    fake_vector_class& operator+=(const fake_vector_class& rhs) {
      int size = sz > rhs.sz ? rhs.sz : sz;
      
      for (int i = 0; i < size; i +=1) {
        elem[i] += rhs.elem[i];
      }

      return *this;
    }

    friend fake_vector_class operator+(fake_vector_class lhs, const fake_vector_class& rhs) {
      lhs += rhs;
      return lhs;
    }

    fake_vector_class& operator++() {
      for (int i = 0; i < sz; i += 1) {
        elem[i] += 1;
      }
      return *this;
    }

    fake_vector_class operator++(int i) {
      fake_vector_class prev_value(*this);
      operator++();
      return prev_value;
    }
    
    friend bool operator==(const fake_vector_class& l, const fake_vector_class& r) {
      if (l.sz != r.sz) return false;

      for (int i = 0; i < l.sz; i += 1) {
        if (l.elem[i] != r.elem[i]) return false;
      }

      return true;
    }

    void print_values() {
      for (int i = 0; i < sz; i += 1) {
        cout << elem[i] << " ";
      }
      cout << endl;
    }
    ~fake_vector_class() {
      delete[] elem;
    }
};

int main() {
  fake_vector_class vector1(5);
  fake_vector_class vector2(5);

  for (int i = 0; i < 5; i += 1) {
    vector1[i] = i + 1;
    vector2[i] = i + 11;
  }

  cout << "Vector 1: ";
  vector1.print_values();
  cout << "Vector 2: ";
  vector2.print_values();

  vector1 += vector2;
  cout << "After doing vector1 += vector2" << endl <<"Vector 1: ";
  vector1.print_values();
  cout << "Vector 2: ";
  vector2.print_values();

  fake_vector_class copy(vector1);
  bool result = copy == vector1;
  cout << "Copy == vector1? = " << result << endl;
  result = copy == vector2;
  cout << "Copy == vector2? = " << result << endl;

  cout << "Vector 1 while doing post-increment: ";
  (vector1++).print_values();
  cout << "Vector 1 after increment: ";
  vector1.print_values();
  cout << "Vector 1 while doing pre-increment: ";
  (++vector1).print_values();

  return 1;
}

