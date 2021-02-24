//
//  Book.hpp
//  Assingment 3
//
//  Created by Account on 2020-02-12.
//  Copyright © 2020 Account. All rights reserved.
//

#ifndef Book_hpp
#define Book_hpp

#include <string>
#include <stdio.h>
#include <iostream>
# include "Reference.hpp"

using namespace std;

class Book : public Reference {
public:
    Book();
    Book(int, string, string, int, string,int);
    
    ~Book();
    int getNumberOfPages();
    void printData();
    
private:
    string publisher;
    int pagesNum;
};
#endif /* Book_hpp */
