#include "base.cpp"

class Derived: public Base
{
private:
    int* m_array;
 
public:
    Derived(int length)
    {
        m_array = new int[length];
    }
 
    virtual const char* getName() const { return "Derived"; }
 
    virtual ~Derived()
    {
        std::cout << "Calling ~Derived()" << std::endl;
        delete[] m_array;
    }
};
