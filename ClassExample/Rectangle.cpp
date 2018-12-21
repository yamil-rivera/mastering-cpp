//
//  Rectangle.cpp
//  ClassExample
//
//  Created by Vo Tri Kien on 12/20/18.
//  Copyright © 2018 Vo Tri Kien. All rights reserved.
//

#include "iostream"
#include "Rectangle.hpp"
using namespace std;

Rectangle::Rectangle(string name, int a, int b) {
    this->name = name; //this: represents a pointer to the object
    width = a;
    height = b;
}
Rectangle::Rectangle() {
    cout << "Constructor called!!" << endl << endl;
}

Rectangle::~Rectangle() {
    cout << this->name << " - Deconstructor called!!!" << endl << endl;
}

Rectangle Rectangle::operator+(const Rectangle &param) {
    Rectangle temp;
    temp.name = name + "+" + param.name;
    temp.width = width + param.width;
    temp.height = height + param.height;
    
    return temp;
}

int Rectangle::getArea() {
    return width * height;
}

Rectangle Rectangle::operator-(const Rectangle &param) {
    Rectangle temp;
    temp.width = width - param.width;
    temp.height = height - param.height;
    
    return temp;
}
