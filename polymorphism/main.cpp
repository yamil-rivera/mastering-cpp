#include <iostream>
#include <vector>
#include <functional>
#include "derived.cpp"

using namespace std;

void printName(const Base base) // note: base passed by value, not reference
{
    cout << "I am a " << base.getName() << '\n';
}

void slicingVectors()
{
	vector<Base> v;
	v.push_back(Base()); // add a Base object to our vector
	v.push_back(Derived(6)); // add a Derived object to our vector
 
        // Print out all of the elements in our vector
	for (int count = 0; count < v.size(); ++count)
		cout << "Index [" << count << "] is a " << v[count].getName() << "\n";
}

void slicingVectorsPtr()
{
	vector<Base*> v;
	v.push_back(new Base()); // add a Base object to our vector
	v.push_back(new Derived(6)); // add a Derived object to our vector
 
  // Print out all of the elements in our vector
	for (int count = 0; count < v.size(); ++count)
		cout << "Index [" << count << "] is a " << v[count]->getName() << "\n";
 
	for (int count = 0; count < v.size(); ++count)
		delete v[count];
}

void slicingVectorsRefWrapper()
{
	vector<reference_wrapper<Base> > v; // our vector is a vector of reference_wrapper wrapped Base (not Base&)
	Base b; // b and d can't be anonymous objects
	Derived d(6);
	v.push_back(b); // add a Base object to our vector
	v.push_back(d); // add a Derived object to our vector
 
	// Print out all of the elements in our vector
	for (int count = 0; count < v.size(); ++count)
		cout << "Index [" << count << "] is a " << v[count].get().getName() << "\n"; // we use .get() to get our element from the wrapper
}

void frankenobject(){
    Derived d1(5);
    Derived d2(6);
    Base &b = d2;
 
    b = d1; // d2 now has the Base portion of d1 and the Derived portion of d2
}

int main()
{
    Derived *derived = new Derived(5);
    Base *base = derived;
    delete base;
 
    Derived d(5);
    Base b = d; // what happens here?
    cout << "b is a " << b.getName() << '\n';
 
    printName(d);
    slicingVectors();
    slicingVectorsPtr();
    slicingVectorsRefWrapper();

    return 0;
}
