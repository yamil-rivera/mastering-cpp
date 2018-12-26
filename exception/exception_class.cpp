#include <iostream>
#include <string>
#include <exception>

using namespace std;

class ArrayException: public exception
{
private:
	string m_error;
 
public:
	ArrayException(string error)
		: m_error(error)
	{
	}
 
	const char* what() const noexcept {
    return m_error.c_str();
  }
};
 
class IntArray
{
private: 
	int m_data[3];

public:
	IntArray() {}
	
	int getLength() { return 3; }
 
	int& operator[](const int index)
	{
		if (index < 0 || index >= getLength())
			throw ArrayException("Invalid indexxxxx");
 
		return m_data[index];
	} 
};
 
int main()
{
	IntArray array;
 
	try
	{
		int value = array[5];
	}
	catch (ArrayException &ex)
	{
		cerr << "An array exception occurred (" << ex.what() << ")\n";
	}
	catch (exception &ex)
	{
		cerr << "Some other std::exception occurred (" << ex.what() << ")\n";
	}
}
