// C++ program to sizes of data types
#include <iostream>
#include <limits>
using namespace std;

typedef struct {
    unsigned int i = 100000;
    unsigned char c1 = 'a';
    unsigned char c2 = 'b';
    unsigned char c3 = 'c';
    unsigned char c4 = 'd';
} my_struct;

typedef struct {
    unsigned short s1 = 100;
    unsigned int i = 100000;
    unsigned short s2 = 200;
} my_disordered_struct;

typedef struct {
    unsigned int i = 100000;
    unsigned short s1 = 100;
    unsigned short s2 = 200;
} my_ordered_struct;

int main()
{
    // Print the sizes of several data types
    cout << "Size of bool : " << sizeof(bool) << " byte" << endl;
    cout << "Bool min value : " << std::numeric_limits<bool>::min() << " Bool max value : " << std::numeric_limits<bool>::max() << endl;
    cout << "Size of char : " << sizeof(char) << " byte" << endl;
    cout << "Char min value : " << (int) std::numeric_limits<char>::min() << " Char max value : " << (int) std::numeric_limits<char>::max() << endl;
    cout << "Size of int : " << sizeof(int) << " bytes" << endl;
    cout << "Int min value : " << std::numeric_limits<int>::min() << " Int max value : " << std::numeric_limits<int>::max() << endl;
    cout << "Size of float : " << sizeof(float) << " bytes" << endl;
        cout << "Float min value : " << std::numeric_limits<float>::min() << " Float max value : " << std::numeric_limits<float>::max() << endl;
    cout << "Size of double : " << sizeof(double) << " bytes" << endl;
        cout << "Double min value : " << std::numeric_limits<double>::min() << " Double max value : " << std::numeric_limits<double>::max() << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << " bytes" << endl;
        cout << "wchar_t min value : " << std::numeric_limits<wchar_t>::min() << " wchar_t max value : " << std::numeric_limits<wchar_t>::max() << endl;
    cout << endl;
    cout << endl;
    
    //Data type modifiers (signed, unsigned, short, long)
    cout << "Size of short int : " << sizeof(short int) << " bytes" << endl;
    cout << "Short int min value : " << std::numeric_limits<short int>::min() << " Short int max value : " << std::numeric_limits<short int>::max() << endl;
    cout << "Size of long int : " << sizeof(long int) << " bytes" << endl;
    cout << "Long int min value : " << std::numeric_limits<long int>::min() << " Long int max value : " << std::numeric_limits<long int>::max() << endl;
    cout << "Size of signed int : " << sizeof(signed int) << " bytes" << endl;
    cout << "Signed int min value : " << std::numeric_limits<signed int>::min() << " Signed int max value : " << std::numeric_limits<signed int>::max() << endl;
    cout << "Size of unsigned int : " << sizeof(unsigned int) << " bytes" << endl;
    cout << "Unsigned int min value : " << std::numeric_limits<unsigned int>::min() << " Unsigned int max value : " << std::numeric_limits<unsigned int>::max() << endl;
    cout << endl;
    cout << endl;

    // Signed vs unsigned
    unsigned char unsigned_char = 0b11111111;
    cout << "Unsigned char (0b11111111): " << (int)unsigned_char << endl;
    signed char signed_char_all_ones = 0b11111111;
    cout << "Signed char (0b11111111): " << (int)signed_char_all_ones << endl;
    signed char signed_char_one = 0b00000001; //Two's complement -> Negate all bits and add one
    cout << "Signed char (0b00000001): " << (int)signed_char_one << endl;
    signed char signed_char_zero = signed_char_all_ones + signed_char_one;
    cout << "Signed char (0b00000000): " << (int)signed_char_zero << endl;
    cout << endl;
    cout << endl;
    
    //Declaration vs initialization
    char uc;
    cout << "Uninitialized char: " << (int) uc << " DOES NOT EXPECT THIS TO BE 0!" << endl;
    int ui;
    cout << "Uninitialized int: " << ui << " DOES NOT EXPECT THIS TO BE 0!"<< endl;
    bool ub;
    cout << "Uninitialized bool: " << ub << " DOES NOT EXPECT THIS TO BE 0!"<< endl;
    char ic = 'A';
    cout << "Initialized char: " << ic << endl;
    int ii = 100;
    cout << "Initialized int: " << ii << endl;
    bool ib = true;
    cout << "Initialized bool: " << ib << endl;
    cout << endl;
    cout << endl;
    
    my_struct a;
    unsigned int* p_i = &a.i;
    unsigned char* p_c = &a.c1;
    cout << "Size of my_struct (int, char): " << sizeof(my_struct) << " bytes" << endl;
    cout << "Address of a.i (int) : " << p_i << endl;
    cout << "Address of a.c (char) : " << (void*) p_c << endl; //We need to cast the pointer becase cout will interpret it as a char and print the actual character associated with the value instead of printing the address.
    cout << "Value of a.i (int) : " << *p_i << endl;
    cout << "Value of a.c (char) : " << *p_c << endl;
    cout << "Value of a.c + 1 (char) : " << *(p_c+1) << endl;
    cout << "Value of a.c + 2 (char) : " << *(p_c+2) << endl;
    cout << "Value of a.c + 3 (char) : " << *(p_c+3) << endl;
    
    cout << "Size of my_disordered_struct (short, int, short): " << sizeof(my_disordered_struct)
    << " bytes" << endl;
    cout << "Size of my_ordered_struct (int, short, short): " << sizeof(my_ordered_struct)
    << " bytes" << endl;
    cout << endl;
    cout << endl;
    return 0;
}
