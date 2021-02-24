//
//  Reference.hpp
//  Assingment 3
//
//  Created by Account on 2020-02-12.
//  Copyright © 2020 Account. All rights reserved.
//

#ifndef Reference_hpp
#define Reference_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <string>



using namespace std;

class Reference {
public:
    Reference();
    Reference(int,string,string,int); //parameters: identifier, title, author, year
    ~Reference();
 
    void virtual printData();
    int getYear();
    int getID();
    string getTitle();
    
private:
    
    int identifier{0};
    string title;
    string author;
    int date{0};
    
};



#endif /* Reference_hpp */
