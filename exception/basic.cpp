#include <iostream>
#include <string>
 
using namespace std;

int main()
{
  try
  {
    //throw -1;
    //throw 1.2;
    throw "exception";
    //string s="exception"; throw s;
    
    cout << "This never prints\n";
  }
  catch (int x)
  {
    cerr << "We caught an int exception with value: " << x << '\n';
  }
  catch (double) // no variable name since we don't use the exception itself in the catch block below
  {
    cerr << "We caught an exception of type double" << '\n';
  }
  catch (const char* exception)
  {
    cerr << "Error: " << exception << '\n';
  }
  catch (...) // catch-all handler
	{
		cerr << "We caught an exception of an undetermined type\n";
	}
 
  cout << "Continuing on our merry way\n";
 
  return 0;
}
