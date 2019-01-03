//
//  main.cpp
//  SmartPointers
//
//  Created by Vo Tri Kien on 1/2/19.
//  Copyright © 2019 Vo Tri Kien. All rights reserved.
//

#include <iostream>
#include <memory>
using namespace std;

/*
1. Use unique_ptr when you want a single pointer to an object that will be reclaimed when that single pointer is destroyed.
2. Use shared_ptr when you want multiple pointers to the same resource.
*/

void testUniquePtr();
void testSharedPtr();

int main(int argc, const char * argv[]) {
    //1. unique_ptr
    testUniquePtr();
    
    //2. shared_ptr
    //testSharedPtr();
    
    return 0;
}

void testUniquePtr() {
    unique_ptr<int> intUniquePtr(new int(10));
    
    cout << "The address of intUniquePtr: " << &intUniquePtr << endl;
    cout << "The value of intUniquePtr is: " << *intUniquePtr << endl;
    cout << "The address that intUniquePtr points to is: " << intUniquePtr.get() << endl << endl; //get(): return the stored pointer
    //cout << "The address that intUniquePtr points to is: " << *intUniquePtr.get() << endl << endl; //get(): return the stored pointer
    
    //unique_ptr<int> otherIntUniquePtr = intUniquePtr; //compile error
    
    unique_ptr<int> otherIntUniquePtr = move(intUniquePtr);
    cout << "The address of otherIntUniquePtr: " << &otherIntUniquePtr << endl;
    cout << "The value of otherIntUniquePtr is: " << *otherIntUniquePtr << endl;
    cout << "The address that otherIntUniquePtr points to is: " << otherIntUniquePtr.get() << endl << endl;
    
    otherIntUniquePtr.release(); //otherIntUniquePtr: null pointer now
    //cout << "The value of otherIntUniquePtr is: " << *otherIntUniquePtr << endl; //runtime error
    //cout << "The value of otherIntUniquePtr is: " << otherIntUniquePtr.get() << endl; //runtime error
    
    int *aNumber = new int(999);
    unique_ptr<int> oneMore;
    oneMore.reset(aNumber);
    cout << "The value of otherIntUniquePtr is: " << *oneMore << "    " << oneMore.get() << endl;
    cout << "aNumber is now: " << aNumber << endl << endl;
}

void testSharedPtr() {
    shared_ptr<int> intSharedPtr(new int(10));
    cout << "The address of intSharedPtr: " << &intSharedPtr << endl;
    cout << "The value of intSharedPtr is: " << *intSharedPtr << endl;
    cout << "The address that intSharedPtr points to is: " << intSharedPtr.get() << endl;
    
    cout << "Number of refs of intSharedPtr: " << intSharedPtr.use_count() << endl;
    
    shared_ptr<int> otherIntSharedPtr = intSharedPtr;
    cout << "Number of refs in intSharedPtr: " << intSharedPtr.use_count() << endl;
    cout << "Number of refs in otherIntSharedPtr: " << otherIntSharedPtr.use_count() << endl;
    
    shared_ptr<int> anotherIntSharedPtr = intSharedPtr;
    cout << "Number of refs in intSharedPtr: " << intSharedPtr.use_count() << endl;
    cout << "Number of refs in otherIntSharedPtr: " << otherIntSharedPtr.use_count() << endl;
    cout << "Number of refs in anotherIntSharedPtr: " << anotherIntSharedPtr.use_count() << endl;
}
