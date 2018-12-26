#include <iostream>
#include <exception>
#include <string>

int main()
{
  try
  {
    std::string s;
    s.resize(-1);
  }
  catch (std::exception &exception)
  {
    std::cerr << "exception: " << exception.what() << '\n';
  }
 
  return 0;
}
