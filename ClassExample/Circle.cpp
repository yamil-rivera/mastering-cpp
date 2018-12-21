//
//  Circle.cpp
//  ClassExample
//
//  Created by Vo Tri Kien on 12/20/18.
//  Copyright © 2018 Vo Tri Kien. All rights reserved.
//

#include "Circle.hpp"

Circle::Circle(double r) {
    radius = r;
}

//double Circle::circum() const {
//    return 2 * radius * 3.14159265;
//}

double Circle::circum() {
   return 2 * radius * 3.14159265;
}

