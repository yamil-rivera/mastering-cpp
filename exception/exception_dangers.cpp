#include <iostream>

int main(){
  try
  {
      Person *john = new Person("John", 18, PERSON_MALE);
      processPerson(john);
      delete john;
  }
  catch (PersonException &exception)
  {
      cerr << "Failed to process person: " << exception.what() << '\n';
  }
}
