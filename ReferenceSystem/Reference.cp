//
//  Reference.cpp
//  Assingment 3
//
//  Created by Account on 2020-02-12.
//  Copyright © 2020 Account. All rights reserved.
//

#include "Reference.hpp"

Reference::Reference(){}

Reference::~Reference(){}

Reference::Reference(int a, string b,string c,int d){
    identifier = a;
    title = b;
    author =c;
    date=d;
}



void Reference::printData(){
    cout << "Title: "<<title<<endl<<"Author: "<<author<<endl<<"date: "<<date<<endl<<"ID: "<<identifier<<endl;
}//print reference data

int Reference::getYear(){
    return date;
}//returns year

int Reference::getID(){
    return identifier;
}

string Reference::getTitle(){
    return title;
}
