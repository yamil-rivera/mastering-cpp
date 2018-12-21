#include <iostream>

using namespace std;

class example {
  private:
    int* value;
  public:
    example(int n) {
      cout << "Normal constructor called" << endl;
      value = new int;
      *value = n;
    }
    example(const example& ex) :
      value(new int)
    {
      cout << "Copy constructor called" << endl;
      *value = *ex.value;
    }
    example& operator=(const example& ex) {
      cout << "Copy assignment called" << endl;
      int* new_value = new int;
      *new_value = *ex.value;
      delete value;
      value = new_value;

      return *this;
    }
    int* get_value() { return value; }
    ~example() {
      delete value;
    }
};

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
      cout << "Copy constructor called" << endl;
      sz = copy.sz;
      elem = new int[sz];
      for(int i=0; i<sz; i++)
        elem[i] = copy.elem[i];
    }

    fake_vector_class& operator=(const fake_vector_class& copy) {
      cout << "Copy assignment called" << endl;
      sz = copy.sz;

      int *new_elem = new int[sz];
      for(int i=0; i<sz; i++)
        new_elem[i] = copy.elem[i];
      delete[] elem;
      elem = new_elem;  

      return *this;
    }

    int size() { return sz; }
    int& operator[](int i) {
      if (i < sz) {
        return elem[i];
      }
      throw "Out of bounds!";
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

void receive_example(example e) {
  cout << "A copy of example received. " << e.get_value() << endl;
}

void play_with_fake_vector() {
  fake_vector_class fake_vector(5);
  
  fake_vector_class fake_vector_2 = fake_vector;
  fake_vector.print_values();
  fake_vector_2.print_values();

  for (int i = 0; i < 5; i += 1) {
    fake_vector[i] = i + 1;
  }

  fake_vector_2 = fake_vector;
  fake_vector.print_values();
  fake_vector_2.print_values();
}
 
int main() {
  /* example ex(1); */
  /* example ex2(2); */
  /* example copy = ex; */

  /* cout << "Local example value address " << ex.get_value() << endl; */
  /* receive_example(ex); */

  /* cout << "Local example2 value address " << ex.get_value() << endl; */
  /* cout << "Local copy value address " << copy.get_value() << endl; */

  /* copy = ex2; */

  /* cout << "Local copy value " << *copy.get_value() << " and address " << copy.get_value() << endl; */
  play_with_fake_vector();
  return 1;
}
