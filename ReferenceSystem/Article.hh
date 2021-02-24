//
//  Article.hpp
//  Assingment 3
//
//  Created by Account on 2020-02-12.
//  Copyright © 2020 Account. All rights reserved.
//

#ifndef Article_hpp
#define Article_hpp
#include <string>
#include <stdio.h>

#include "Reference.hpp"

using namespace std;

class Article : public Reference {
public:
    Article();
    Article(int, string, string, int, string,int,int);
    ~Article();
    int getstartPage();
    int getendPage();
    void printData();
private:
    string journalName;
    int startPage;
    int endPage;
    
};

#endif /* Article_hpp */
