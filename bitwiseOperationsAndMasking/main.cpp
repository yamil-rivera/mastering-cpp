#include<iostream>
#include<bitset>
using namespace std;

int main(int argc, const char * argv[]) {
    const unsigned char first_bit = 0b00000001;
    const unsigned char second_bit = 0b00000010;
    const unsigned char third_bit = 0b00000100;
    const unsigned char fourth_bit = 0b00001000;
    const unsigned char fifth_bit = 0b00010000;
    const unsigned char sixth_bit = 0b00100000;
    const unsigned char seventh_bit = 0b01000000;
    const unsigned char eighth_bit = 0b10000000;

    unsigned char result = 0;
    
    //Setting second bit
    result = 0;
    result = result | second_bit;
    cout << "Setting second bit" << endl;
    cout << bitset<8>(result) << endl;
    
    //Setting second and fourth bits
    result = 0;
    result = result | (second_bit | fourth_bit);
    cout << "Setting second and fourth bits" << endl;
    cout << bitset<8>(result) << endl;
    
    //Turn off second bit
    result = result & ~second_bit;
    cout << "Turn off second bit" << endl;
    cout << bitset<8>(result) << endl;
    
    result = 0b00000101;
    //Turn off third and first bits;
    result = result & ~(third_bit | first_bit);
    cout << "Turn off third and first bits" << endl;
    cout << bitset<8>(result) << endl;
    
    //Toggling fifth bit
    result = result ^ fifth_bit;
    cout << "Toggling fifth bit" << endl;
    cout << bitset<8>(result) << endl;
    
    //Toggling eight bit
    result = result ^ eighth_bit;
    cout << "Toggling eight bit" << endl;
    cout << bitset<8>(result) << endl;
    
    //Toggling fifth bit AGAIN!
    result = result ^ fifth_bit;
    cout << "Toggling fifth bit AGAIN!" << endl;
    cout << bitset<8>(result) << endl;
    
    //Shift the bits one position to the left
    result = 0b00001011;
    result = result << 1;
    cout << "Shift the bits one position to the left" << endl;
    cout << bitset<8>(result) << endl;
    
    //Shift the bits two positions to the right
    result = result >> 2;
    cout << "Shift the bits two positions to the right" << endl;
    cout << bitset<8>(result) << endl;
    
    const unsigned char two_msb_mask = 0b11000000;
    
    //Getting the two most significant bits of 0b11001101;
    result = 0b11001101;
    unsigned char two_msb = result & two_msb_mask;
    cout << "Getting the two most significant bits of 0b11001101" << endl;
    cout << bitset<8>(two_msb) << endl;
    
}
