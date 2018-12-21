//
//  Rectangle.hpp
//  ClassExample
//
//  Created by Vo Tri Kien on 12/20/18.
//  Copyright © 2018 Vo Tri Kien. All rights reserved.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>

#endif /* Rectangle_hpp */

class Rectangle {
    std::string name;
    int width;
    int height;
public:
    Rectangle(std::string, int, int);
    Rectangle();
    ~Rectangle();
    
    Rectangle operator + (const Rectangle &param);
    Rectangle operator - (const Rectangle &param);
    
    int getArea();
};


