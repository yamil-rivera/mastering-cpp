#include <iostream>

template <class T>
class Storage8
{
private:
    T m_array[8];
 
public:
    void set(int index, const T &value)
    {
        m_array[index] = value;
    }
 
    const T& get(int index)
    {
        return m_array[index];
    }
};

template <>
class Storage8<bool> // we're specializing Storage8 for bool
{
private:
    unsigned char m_data;
 
public:
    Storage8() : m_data(0)
    {
    }
 
    void set(int index, bool value)
    {
        // Figure out which bit we're setting/unsetting
        // This will put a 1 in the bit we're interested in turning on/off
        unsigned char mask = 1 << index;
 
        if (value)  // If we're setting a bit
            m_data |= mask;  // Use bitwise-or to turn that bit on
        else  // if we're turning a bit off
            m_data &= ~mask;  // bitwise-and the inverse mask to turn that bit off
    }
    
    bool get(int index)
    {
        // Figure out which bit we're getting
        unsigned char mask = 1 << index;
        // bitwise-and to get the value of the bit we're interested in
        // Then implicit cast to boolean
        return (m_data & mask) != 0;
    }
};

int main() {
    // Define a Storage8 for integers
    Storage8<int> intStorage;
 
    for (int count=0; count<8; ++count)
        intStorage.set(count, count);
 
    for (int count=0; count<8; ++count)
        std::cout << intStorage.get(count) << '\n';
 
    // Define a Storage8 for bool
    Storage8<bool> boolStorage;
    for (int count=0; count<8; ++count)
        boolStorage.set(count, count & 3);
 
    for (int count=0; count<8; ++count)
        std::cout << (boolStorage.get(count) ? "true" : "false") << '\n';
 
    return 0;
}
