//
//  Article.cpp
//  Assingment 3
//
//  Created by Account on 2020-02-12.
//  Copyright © 2020 Account. All rights reserved.
//

#include "Article.hpp"


Article::Article(){}
Article::Article(int a, string b,string c,int d, string e, int f, int g) :Reference(a,b,c,d) {
    journalName = e;
    startPage = f;
    endPage = g;
}
Article::~Article(){}


int Article::getstartPage(){
    
    return startPage;
}

int Article::getendPage(){
    
    return endPage;
}

void Article::printData(){
    
    Reference::printData( );
    cout << "Journal name: "<<journalName<<endl<"startpage"<<startPage<<endl<< "end page: "<<endPage<<endl;
}
