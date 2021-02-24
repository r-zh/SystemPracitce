//
//  TextBook.cpp
//  Assingment 3
//
//  Created by Account on 2020-02-12.
//  Copyright © 2020 Account. All rights reserved.
//

#include "TextBook.hpp"
TextBook::TextBook(){}//default constructor


TextBook::TextBook(int a, string b,string c,int d, string e, int f, string g): Book(a,b, c, d, e, f){

    URL = g;
}

TextBook::~TextBook(){}//destructor


void TextBook::printData(){
    Book::printData();
    cout<< "Textbook website" << URL <<endl;
}

string TextBook::getURL(){
    return URL;
}//gets URL
