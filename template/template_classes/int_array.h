#ifndef INTARRAY_H
#define INTARRAY_H
 
#include <assert.h> // for assert()
 
class IntArray
{
private:
    int m_length;
    int *m_data;
 
public:
    IntArray()
    {
        m_length = 0;
        m_data = nullptr;
    }
 
    IntArray(int length)
    {
        assert(length > 0);
        m_data = new int[length];
        m_length = length;
    }
 
    ~IntArray()
    {
        delete[] m_data;
    }
 
    void Erase()
    {
        delete[] m_data;
        // We need to make sure we set m_data to 0 here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }
 
    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
 
    int getLength() { return m_length; }
};
 
#endif
