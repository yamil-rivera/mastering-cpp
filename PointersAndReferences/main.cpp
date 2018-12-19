#include <iostream>

using namespace std;

void declarePointers();
void declarePointerOfPointer();
void uninitailizedPointer();
void nullPointers();

void pointerArithmetic();
void functionPointer();
void dynamicMemoryAllocation();

void referenceVariables();

int main(int argc, const char * argv[]) {
    char *aString = "";
    //1. Declare and initialize pointers
    //declarePointers();
    
    //2. Declare pointers of pointers
    //declarePointerOfPointer();
    
    //3. Unitialized pointers
    //uninitailizedPointer();
    
    //4. Null pointers
    //nullPointers();
    
    //5. Pointer Arithmetic
    //pointerArithmetic();
    
    //6. Function pointer
    //functionPointer();
    
    //7. Pointers and Dynamic memory allocation
    //dynamicMemoryAllocation();
    
    //8. References Variables
    //referenceVariables();
    
    return 0;
}

void declarePointers() {
    // Deaclare normal variables
    double aDouble = 1.2;
    int anInt = 10;
    char aChar = 'e';
    bool aBool = true;
    
    // Declare and initialize pointer variables
    double *aDoublePtr = &aDouble;
    int *anIntPtr = &anInt;
    char *aCharPtr = &aChar;
    bool *aBoolPtr = &aBool;
    
    cout << "Size of aDoublePtr: " << sizeof(aDoublePtr) << endl;
    cout << "Value of aDoublePtr: " << aDoublePtr << endl;
    cout << "The value that aDoublePtr points to: " << *aDoublePtr << endl << endl;
    
    cout << "Size of anIntPtr: " << sizeof(anIntPtr) << endl;
    cout << "Value of anIntPtr: " << anIntPtr << endl;
    cout << "The value that anIntPtr points to: " << *anIntPtr << endl << endl;
    
    cout << "Size of aCharPtr: " << sizeof(aCharPtr) << endl;
    cout << "Value of aCharPtr: " << (aCharPtr) << endl; //operator << interprets that as a C string, and tries to print a character sequence instead of its address.
    cout << "The value that aCharPtr points to: " << *aCharPtr << endl << endl;
    
    cout << "Size of aBoolPtr: " << sizeof(aBoolPtr) << endl;
    cout << "Value of aBoolPtr: " << aBoolPtr << endl;
    cout << "The value that aBoolPtr points to: " << *aBoolPtr << endl << endl;
}

void declarePointerOfPointer() {
    // Deaclare normal variables
    double aDouble = 1.2;
    
    // Declare and initialize pointer variables
    double *aDoublePtr = &aDouble;
    
    // Declare pointers of pointers
    double **ptrOfADoublePtr = &aDoublePtr;
    
    cout << "Address of aDouble: " << &aDouble << endl;
    cout << "Value of ptrOfADoublePtr: " << ptrOfADoublePtr << endl;
    cout << "The value that ptrOfADoublePtr points to: " << *ptrOfADoublePtr << endl;
    cout << "The actual value: " << **ptrOfADoublePtr << endl;
}

void uninitailizedPointer() {
    double aDouble = 10;
    double *aPtr;
    *aPtr = 12;
    
    cout << "The address of aDouble: " << &aDouble << endl;
    cout << "The address of aPtr: " << &aPtr << endl;
    cout << "The address aPtr holding: " << aPtr << endl;
    cout << "The value aPtr points to: " << *aPtr << endl;
}

void nullPointers() {
    int *ptr = 0;
    int *nullPtr = nullptr;
    
    cout << "Value of ptr: " << ptr << endl;
    //cout << "Dereferencing of ptr: " << *ptr << endl; // Error: EXC_BAD_ACCESS
    
    cout << "Value of ptr: " << nullPtr << endl;
    //cout << "Dereferencing of ptr: " << *nullPtr << endl; // Error: EXC_BAD_ACCESS
}

void pointerArithmetic() {
    double aDouble = 1.2;
    double *aDoublePtr = &aDouble;
    
    cout << "Value of aDoublePtr: " << aDoublePtr << endl;
    cout << "The value that aDoublePtr points to: " << *aDoublePtr << endl;
    cout << "Value of ++aDoublePtr: " << ++aDoublePtr << endl;
    cout << "Value of ++aDoublePtr: " << *(++aDoublePtr) << endl << endl;
    
    double array[] = {2.3, 4.5};
    cout << "Value of array: " << array << endl;
    cout << "The value that array points to: " << *array << endl;
    cout << "Value of array + 1: " << array + 1 << endl;
    cout << "The value that array + 1 points to: " << *(array + 1) << endl << endl;
    
    /* This causes compile error because we are changing array's address
    cout << "Value of array++: " << array++ << endl;
    cout << "The value that array++ points to: " << *(array++) << endl;
     */
}

// Take 3 arguments, 2 int's and a function pointer
//   int (*)(int, int), which takes two int's and return an int
int arithmetic(int, int, int (*)(int, int));
int add(int, int);
int subtract(int, int);

int add(int n1, int n2) { return n1 + n2; }
int subtract(int n1, int n2) { return n1 - n2; }
int arithmetic(int n1, int n2, int (*operationName) (int, int)) {
    return (*operationName)(n1, n2);
}

void functionPointer() {
    int number1 = 5;
    int number2 = 6;
    
    // add
    cout << "The resutl of add is: " << arithmetic(number1, number2, add) << endl;
    // subtract
    cout << "The resutl of subtract is: " << arithmetic(number1, number2, subtract) << endl;
}

void dynamicMemoryAllocation() {
    double aDouble = 12.8;
    double *aDoublePtr = &aDouble;
    
    cout << "Address of aDoublePtr: " << &aDoublePtr << endl;
    cout << "Value of aDoublePtr: " << aDoublePtr << endl;
    cout << "The value that aDoublePtr points to: " << *aDoublePtr << endl << endl;
    
    aDoublePtr = new double(9.3);
    cout << "Address of aDoublePtr: " << &aDoublePtr << endl;
    cout << "Value of aDoublePtr: " << aDoublePtr << endl;
    cout << "The value that aDoublePtr points to: " << *aDoublePtr << endl;
    
    delete aDoublePtr;
}

void referenceVariables() {
    double aDouble = 20.9;
    double &aDoubleRef = aDouble;
    double *aDoublePtr = &aDoubleRef;
    
    cout << "Value of aDouble: " << aDouble << endl;
    cout << "Value of aDoubleRef: " << aDoubleRef << endl;
    cout << "Address of aDouble: " << &aDouble << endl;
    cout << "Address of aDoubleRef: " << &aDoubleRef << endl << endl;
    
    cout << "Value of aDoublePtr: " << aDoublePtr << endl;
    cout << "Address of aDoublePtr: " << &aDoublePtr << endl;
    cout << "The value aDoublePtr points to: " << *aDoublePtr << endl << endl;
    
    double aDouble2 = 90.8;
    aDoubleRef = aDouble2;
    cout << "Value of aDouble: " << aDouble << endl;
    cout << "Value of aDoubleRef: " << aDoubleRef << endl;
    
    cout << "Address of aDouble: " << &aDouble << endl;
    cout << "Address of aDoubleRef: " << &aDoubleRef << endl;
    cout << "Address of aDouble2: " << &aDouble2 << endl;
}
