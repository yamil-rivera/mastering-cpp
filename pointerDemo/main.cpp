// C++ program to illustrate call-by-methods in C++ 
  
#include <iostream>
using namespace std;

//Pass-by-Value 
int square1(int n)
{ 
    //Address of n in square1() is not the same as n1 in main() 
    cout << "address of n1 in square1(): " << &n << endl;   
      
    // clone modified inside the function 
    n = n*n;
    return n;
}

//Pass-by-Reference with Pointer Arguments 
void square2(int *n)
{ 
    //Address of n in square2() is the same as n2 in main() 
    cout << "address of n2 in square2(): " << n << endl; 
      
    // Explicit de-referencing to get the value pointed-to 
    *n = *n * *n;
}

//Pass-by-Reference with Reference Arguments 
void square3(int &n)
{ 
    //Address of n in square3() is the same as n3 in main() 
    cout << "address of n3 in square3(): " << &n << endl; 
      
    // Implicit de-referencing (without '*') 
    n = n*n;
}

void pointer_demo()
{ 
    //Call-by-Value 
    int n1 = 8;
    cout << sizeof(int) << endl;
    cout << "address of n1 in main(): " << &n1 << endl;
    int n1_squared = square1(n1);
    cout << "Square of n1: " << n1_squared << endl;
      
    //Call-by-Reference with Pointer Arguments 
    int n2 = 8;
    cout << "address of n2 in main(): " << &n2 << endl; 
    square2(&n2);
    cout << "Square of n2: " << n2 << endl;
      
    //Call-by-Reference with Reference Arguments 
    int n3 = 8;
    cout << "address of n3 in main(): " << &n3 << endl; 
    square3(n3);
    cout << "Square of n3: " << n3 << endl;

    //Declare an array
    int val[3] = { 5, 10, 20 };

    //declare pointer variable and
    //Assign the address of val[0] to ptr
    // We can use ptr=&val[0];(both are same)
    int *ptr = val;

    cout << "Elements of the array are: ";
    cout << ptr[0] << " " << ptr[1] << " " << ptr[2] << endl;
    cout << "I can dereference an element that is not part of the array! : " << ptr[3] << endl;
}

//Driver program 
int main() 
{ 
    pointer_demo();
} 