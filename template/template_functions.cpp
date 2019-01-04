#include <iostream>
using namespace std;

// int max2(int x, int y)
// {
//     return (x > y) ? x : y;
// }

// double max2(double x, double y)
// {
//     return (x > y) ? x : y;
// }

template <typename T>
const T& max2(const T& x, const T& y)
{
    return (x > y) ? x : y;
}

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents)
        : m_cents(cents)
    {
    }

    friend bool operator>(const Cents &c1, const Cents &c2)
    {
        return (c1.m_cents > c2.m_cents);
    }

    friend std::ostream& operator<< (std::ostream &out, const Cents &cents)
    {
        out << cents.m_cents << " cents ";
        return out;
    }
};

int main() {
    int i = max2(3, 7);
    cout << i << '\n';
 
    double d = max2(6.34, 18.523);
    cout << d << '\n';
 
    char ch = max2('a', '6');
    cout << ch << '\n';
 
    Cents nickle(5);
    Cents dime(10);
 
    Cents bigger = max2(nickle, dime);
    cout << bigger << '\n';

    return 0;
}
