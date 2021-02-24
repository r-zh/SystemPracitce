//
//  TextBook.hpp
//  Assingment 3
//
//  Created by Account on 2020-02-12.
//  Copyright © 2020 Account. All rights reserved.
//

#ifndef TextBook_hpp
#define TextBook_hpp
#include <string>
#include <stdio.h>
#include "Book.hpp"
using namespace std;

class TextBook : public Book{
public:
    TextBook();
    TextBook(string,int,string,string,int,string,int,string);
    ~TextBook();
    void printData();
    string getURL();
    
private:
    string URL;

};

#endif /* TextBook_hpp */
