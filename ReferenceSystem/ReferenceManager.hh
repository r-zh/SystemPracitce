//
//  ReferenceManager.hpp
//  Assingment 3
//
//  Created by Account on 2020-02-12.
//  Copyright © 2020 Account. All rights reserved.
//

#ifndef ReferenceManager_hpp
#define ReferenceManager_hpp

#include "Article.hpp"
#include "Book.hpp"
#include "TextBook.hpp"
#include <stdio.h>
#include "Reference.hpp"


class ReferenceManager{
public:
    ReferenceManager();
    ~ReferenceManager();
    bool addReference(Reference *);
    void printReferences();
    bool deleteReference(int);
    bool search(int);
    int get(int);
    int getSize();
    
private:
    
    static const int capacity =100;
    // Pointer array to store pointers to objects in the Reference hieararchy
    Reference * array[capacity];
    int size{0};
};


#endif /* ReferenceManager_hpp */
