#ifndef DOUBLEARRAY_H
#define DOUBLEARRAY_H
 
#include <assert.h> // for assert()
 
class DoubleArray
{
private:
    int m_length;
    double *m_data;
 
public:
    DoubleArray()
    {
        m_length = 0;
        m_data = nullptr;
    }
 
    DoubleArray(int length)
    {
        assert(length > 0);
        m_data = new double[length];
        m_length = length;
    }
 
    ~DoubleArray()
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
 
    double & operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
 
    int getLength() { return m_length; }
};
 
#endif
