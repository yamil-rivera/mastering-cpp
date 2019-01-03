#include <iostream>

class Base
{
public:
    virtual const char* getName() const { return "Base"; }

    // always make your destructors virtual if you’re dealing with inheritance
    virtual ~Base()
    {
        std::cout << "Calling ~Base()" << std::endl;
    }
};
