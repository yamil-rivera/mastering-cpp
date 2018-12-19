#include <iostream>
#include <cstring>
#include <cwchar>

using namespace std;

int get_string_len(char* str) {
  int len = 0;
  while(*str++ != '\0') {
    len++;
  }

  return len;
}

void string_functions() {
  char str[] = "A new string :)";

  cout << "Some useful string functions inside cstring header file" << endl;
  cout << "To get the length of a string we use strlen()" << endl;
  cout << "The string \"" << str << "\" is " << strlen(str) << " long." << endl << endl;

  /* 
   * strcomp returns
   * > 0 if first string is aphabetical greater
   * < 0 if first string is alphabetical lower
   * == 0 if both strings are equal
  */
  cout << "Since doing str == another_str compares the references and not the actual string, to compare a string we use strcmp()" << endl;
  cout << strcmp(str, "A new string :)") << endl;
  cout << strcmp(str, "A neW string :)") << endl;
  cout << strcmp("stRing", "string") << endl << endl;

  char str_copy[100];
  cout << "To copy a string to a new string we use strcpy()" << endl;
  strcpy(str_copy, str);
  str[0] = 'a';
  cout << "Original modified: " << str << endl;
  cout << "Copy: " << str_copy << endl << endl;

  cout << "To concatenate 2 strings we use strcat()" << endl;
  strcat(str_copy, " with more things!");
  cout << "Resulting string: " << str_copy << endl << endl;

  cout << "A good example and reason of why we don't like to use this kind of strings:" << endl;
  cout << "To split a string into multiple tokens according to 1 or multiple delimiters we use strtok()" << endl;
  /*
   * This function receives the string to be analized and the delimiters
   * Returns a pointer to a string with first/next token
   * To continue scanning a string we need to pass NULL as the first parameter
   */
  char* token = strtok(str, " ");
  while(token != NULL) {
    cout << token << endl;
    token = strtok(NULL, " ");
  }
}

void display_all_ascii() {
  for (char ch = 0; ch < numeric_limits<char>::max(); ch += 1) {
    cout << ch;
  }
}

void wchar_examples() {
  wchar_t wstr[] = L"A wide string \u00C0";

  wcout << wstr;
  cout << endl << "It works exactly the same as a normal char string but supporting unicode characters" << endl;
}

int main() {
  char ch = 'a';
  char c_string[] = "this is a c string!";
  char unitialized_string[27];

  cout << "C string = " << c_string << endl;
  cout << "Third character of c string = " << c_string[2] << endl;
  c_string[2] = ch;
  cout << "C string with third value changed = " << c_string << endl;
  cout << "Every string has \\0 as their end value." << endl << endl;

  // length
  cout << "length of c_string: " << get_string_len(c_string) << endl;
  cout << "Last character of c_string: " << c_string[get_string_len(c_string) - 1] << endl << endl;

  cout << "Each char has an int value acording to the ASCII value." << endl;
  cout << "We can do some math with them." << endl;
  int len = get_string_len(c_string);
  for(int i = 0; i < len; i += 1) {
    c_string[i] += 1;
  }
  cout << "Modified string is: \"" << "\"" << c_string << endl << endl;

  cout << "We can dinamically create a string." << endl;
  cout << "Let's create a string!" << endl;
  for (int i = 0; i < 26; i += 1) {
    unitialized_string[i] = i + 'A';
  }
  unitialized_string[26] = '\0';
  cout << "Created string is = " << unitialized_string << endl << endl;

  string_functions();
  char string[10] = "123456789";
  cout << string << endl;
  string[9] = '0';
  char* pc = &string[0];
  cout << pc << endl;
  cout << "All ASCII values for char: " << endl << endl;
  display_all_ascii();
  cout << endl << endl;

  wchar_examples();
}
