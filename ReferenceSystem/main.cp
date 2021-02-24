//
//  main.cpp
//  Assingment 3
//
//  Created by Account on 2020-02-12.
//  Copyright © 2020 Account. All rights reserved.
//

#include <iostream>
#include "Reference.hpp"
#include "Article.hpp"
#include "Book.hpp"
#include "TextBook.hpp"
#include "ReferenceManager.hpp"
using namespace std;

int main() {
    
    ReferenceManager manager();
   
    
        int type;
        int tempIdentifier;
        string tempTitle;
        string tempAuthor;
        int tempYear;
        string tempPublisher;
        int tempNumOfPages;
        string tempURL;
        string tempJournalInfo;
        int tempStartPage;
        int tempEndPage;
        
        cout << "for reference " << i << " create a book, textbook or article\nby entering 1, 2, or 3 respectively and to terminate the adding of references enter 0\n";
        cin >> type;
        
        while ( type != 0)
        {
        //following four loops check what user entered
        if(type == 1){
            
            //title, identifier, author, year , publisher, number of pages
            cout << "FOR A BOOK, enter identifier,title, author, year,\npublisher and number of pages\n";
            cin >> tempIdentifier;
            cin >> tempTitle;
            cin >>tempAuthor;
            cin >> tempYear;
            cin >>tempPublisher;
            cin >> tempNumOfPages;
        Book* temp1 = new Book(tempIdentifier,tempTitle,tempAuthor, tempYear, tempPublisher,tempNumOfPages);
            
            manager.addReference(temp1);
            
        }
        
        else if(type==2){
            cout << "FOR A TEXTBOOK, enter identifier, title, author, year,\npublisher and number of pages, and URL\n";
            cin >> tempIdentifier;
            cin >> tempTitle;
            cin >>tempAuthor;
            cin >> tempYear;
            cin >>tempPublisher;
            cin >> tempNumOfPages;
            cin >>tempURL;
            Textbook * temp2= new Textbook(tempIdentifier, tempTitle,tempAuthor, tempYear, tempPublisher,tempNumOfPages, tempURL);
            manager.addReference(temp2);
            
        }
        
        else if(type == 3){
            cout << "FOR AN ARTICLE, enter identifier, title, author, year,\njournal information, start page, and end page\n";
            
           cin >> tempIdentifier;
        
            cin >> tempTitle;
            cin >>tempAuthor;
            cin >> tempYear;
            cin >>tempJournalInfo;
            cin >> tempStartPage;
            cin >> tempEndPage;
            Article * temp3= new Article(tempIdentifier,tempTitle,tempAuthor, tempYear, tempJournalInfo,tempStartPage,tempEndPage);
            manager.addReference(temp3);
        }
        
        else{
            cout << "invalid choice\n";
            i--;
        }
    }
    
    //prints data after its created
    cout << "***BOOK INFORMATION***\n";
    manager.printReferences();
    
    //getting identifier
    int getting1;
    cout << "enter position of object to \nrecieve its identifier\n";
    cin >> getting1;
    int result3 =manager.get(getting1);
    cout << "identifier at position "<<getting1<<" is: "<<result3<<endl;
    
    //searching item
    int searching;
    cout << "enter an ID you'd like to search for\n";
    cin>>searching;
    int result = manager.search(searching);
    if(result == 1){
        cout << "the identifier exists\n";
    }
    else{
        cout << "the identifier doesnt exist\n";
    }
    
    
    //deleting item
    int deleting;
    cout << "enter the position of the element you'd \nlike to delete\n";
    cin >> deleting;
    int result2 = manager.deleteReference(deleting);
    if(result2 == 0){
        cout << "pos was not a valid index\n";
    }
    
    cout << "***BOOK INFORMATION***\n";
    manager.printReferences();
}//menu for user interaction

    
    
    return 0;
}
