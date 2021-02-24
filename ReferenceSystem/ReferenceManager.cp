//
//  ReferenceManager.cpp
//  Assingment 3
//
//  Created by Account on 2020-02-12.
//  Copyright © 2020 Account. All rights reserved.
//

#include "ReferenceManager.hpp"

ReferenceManager::ReferenceManager(){}//default constructor

ReferenceManager::~ReferenceManager(){}//default destructor



bool ReferenceManager::addReference(Reference * A){
   
    if(size == capacity){
        cout << "*WARNING* capacity is full\n";
        return false;
    }
    
    array[size]= A;
    size++;
        return true;
}//add reference

void ReferenceManager::printReferences(){

    for(int i=0;i<size;i++){
        cout << endl;
        cout << "reference "<<i<<endl;
        array[i]->printData();
        
    }

}//print reference

int ReferenceManager::getSize(){
    return size;
}//returns the number of refernces

bool ReferenceManager::deleteReference(int a){
    if(a>=size){
        cout << "*WARNING* entered invalid index\n";
        return false;
    }
    else{
        // Shifting the elements of the array.
        for(int i=a;i<size-1;i++){

            array[i] = array[i+1];
    }
    size --;
    return true;
}//removes item from array at index a

bool ReferenceManager::search(int ID){
    for(int i=0;i<size;i++){
        if(array[i]->getID()==ID){
            
            return true;
        }
    }
    cout << "*WARNING* ID not found\n";
    return false;
}//searches if ID exists


int ReferenceManager::get(int A){
    
    return array[A]->getID();
}//returns ID of object a


//main menu for user interaction**********************************
void ReferenceManager::menu(){
    
    
    
