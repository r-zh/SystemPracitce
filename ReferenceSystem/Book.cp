//
//  Book.cpp
//  Assingment 3
//
//  Created by Account on 2020-02-12.
//  Copyright © 2020 Account. All rights reserved.
//

#include "Book.hpp"



Book::Book(int a, string b,string c,int d, string e, int f): Reference(a,b,c,d){
    publisher = e;
    pagesNum = f;

}//special constructor

Book::~Book(){}//default destructor


int Book::getNumberOfPages(){

    return pagesNum;
}

void Book::printData(){
    Reference:: printData();
    
  cout << "Publisher: "<<publisher<<endl<< "number of pages: "<<pagesNum<<endl;
}

int Book::getNumberOfPages(){
    return pagesNum;
}//returns number of pages
