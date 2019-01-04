//
//  main.cpp
//  Containers
//
//  Created by Vo Tri Kien on 1/3/19.
//  Copyright © 2019 Vo Tri Kien. All rights reserved.
//

#include <iostream>
#include <deque>
#include <list>
#include <set>
#include <map>
using namespace std;

class Object {
    int value;
public:
    Object(int val) {
        value = val;
    }
    int getValue() const {
        return value;
    }
    
    bool operator< (const Object &param1) const {
        return this->getValue() < param1.getValue();
    }
};

void testDeque();
void testList();
void testSet();
void testMap();

int main(int argc, const char * argv[]) {
    //1. deque
    //testDeque();
    
    //2. list
    //testList();
    
    //3. set
    //testSet();
    
    //4. map
    testMap();
}

//Double-ended queues are sequence containers with dynamic sizes
//that can be expanded or contracted on both ends (either its front or its back).
void testDeque() {
    deque<int> first_deque = deque<int>(10);
    
    cout << "size: " << first_deque.size() << endl;
    
    for(int i = 0; i < first_deque.size(); i++) {
        first_deque[i] = i + 1;
    }
    
    for(int i = 0; i < first_deque.size(); i++) {
        cout << first_deque[i] << " ";
        cout << first_deque[i] << " " << &first_deque[i] << endl;
    }
    cout << endl;
    
    deque<int> second_deque;
    for (int i=1; i<=5; i++) {
        second_deque.push_back(i);
    }
    second_deque.push_front(111);
    second_deque.push_back(322);
    
    deque<int>::iterator it = second_deque.begin();
    while (it != second_deque.end()) {
        cout << " " << *it++;
    }
    cout << endl << "The first element is: " << second_deque.front();
    cout << endl << "The element at 3 is: " << second_deque.at(2);
    cout << endl << "The last element is: " << second_deque.back();
    
    cout << endl;
    
    first_deque.push_front(444);
    first_deque.push_front(555);
    
    for(int i = 0; i < first_deque.size(); i++) {
        cout << first_deque[i] << " " << &first_deque[i] << endl;
    }
    
    cout << endl;
}

//list is implemented as doubly-linked list
void testList() {
    list<Object> first_list;
    list<Object> second_list;
    
    for (int i=1; i<=5; ++i) {
        first_list.push_back(i);
    }
    list<Object>::iterator it = first_list.begin();
    while (it != first_list.end()) {
        cout << it->getValue() << " ";
        it++;
    }
    cout << endl;
    
    for (int i=1; i<=5; ++i) {
        second_list.push_back(i*10);
    }
    list<Object>::iterator it2 = second_list.begin();
    while (it2 != second_list.end()) {
        cout << it2->getValue() << " ";
        it2++;
    }
    cout << endl;
    
    //Transfers elements from x into the container, inserting them at position.
    first_list.splice(++first_list.begin(), second_list);
    it = first_list.begin();
    while (it != first_list.end()) {
        cout << it->getValue() << " ";
        it++;
    }
    
    cout << endl;
}

//Sets are containers that store unique elements following a specific order.
void testSet() {
    set<Object> first_set;
    first_set.insert(Object(111));
    first_set.insert(Object(111));
    first_set.insert(Object(222));
    first_set.insert(Object(99));
    
    cout << "size of first_set is " << first_set.size() << endl;
    
    set<Object>::iterator it = first_set.begin();
    while(it != first_set.end()) {
        cout << it->getValue() << endl;
        it++;
    }
    
    it = first_set.find(111.0);
    cout << it->getValue() << endl;
}

//combination of a key value and a mapped value, following a specific order.
void testMap() {
    map<int, Object> first_map;
    first_map.insert(pair<int, Object>(5, Object(56)));
    first_map.insert({1, Object(1)});
    first_map.insert({2, Object(2)});
    first_map.insert({2, Object(34)}); //not replace old one
    
    map<int, Object>::iterator it = first_map.begin();
    while(it != first_map.end()) {
        cout << it->first << " " << it->second.getValue() << endl;
        it++;
    }
}


