//
//  main.cpp
//  ClassExample
//
//  Created by Vo Tri Kien on 12/20/18.
//  Copyright © 2018 Vo Tri Kien. All rights reserved.
//

#include <iostream>
#include "Rectangle.hpp"
#include "Circle.hpp"
using namespace std;

void withRectangleClass();
void withCircleClass();

int main(int argc, const char * argv[]) {
    withRectangleClass();
    
    //withCircleClass();
    
    
    //class and struct keywords are the same. Diff is: struct default access is public, but class is private
    //Exercise is to define Rectangle class and overload the operator -
    
    return 0;
}

void withRectangleClass() {
    Rectangle rectA("RectA", 10, 20); //Rectangle rectA = Rectangle("RectA", 10, 20);
    Rectangle *rectB = new Rectangle("RectB", 2, 6);
    Rectangle rectD("RectD", 1,2);
    
    cout << "The area of rectA is: " << rectA.getArea() << endl;
    cout << "Address of rectA is: " << &rectA << endl << endl;
    
    cout << "The area of rectB is: " << rectB->getArea() << endl;
    cout << "Address of rectB is: " << rectB << endl << endl;
    
    Rectangle rectC = rectA + *rectB + rectD;
    cout << "The area of rectC is: " << rectC.getArea() << endl;
    cout << "Address of rectC is: " << &rectC << endl << endl;
    
    delete rectB;
}

void withCircleClass() {
    Circle foo (10.0);   // functional form
    const Circle bar = 20.0;   // assignment init.
    Circle baz {30.0};   // uniform init.
    Circle qux = {40.0}; // POD-like (Plain Old Data)
    
    cout << "foo's circumference: " << foo.circum() << endl << endl;
    //cout << "bar's circumference: " << bar.circum() << endl << endl;
}
