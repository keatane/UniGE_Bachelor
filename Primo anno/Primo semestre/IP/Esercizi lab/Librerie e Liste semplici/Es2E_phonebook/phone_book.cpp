#include "phone_book.h"
#include <iostream>

struct Contact_Str_Impl{

    std::string name;
    std::string surname;
    long int phone;

};


void add(PhoneBook& B, std::string surname, std::string name, long int phoneNumber){

    Contact_Str C = new Contact_Str_Impl;
    C->name = name;
    C->surname = surname;
    C->phone = phoneNumber;
    B.push_back(C);

}

void print(const PhoneBook& B){

    std::cout << "\n\n";
    for(int i = 0; i < B.size(); i++){

        std::cout << "\n"+std::to_string(i+1)+")\n\n";
        std::cout << "Name: " << B[i]->name << std::endl;
        std::cout << "Surname: " <<B[i]->surname << std::endl;
        std::cout << "Phone: " <<B[i]->phone << std::endl;
            
    }
    
    std::cout << "\n\n";
}


void sortSurnames(PhoneBook& B){
  
  for(int i = 0; i < B.size(); i++){
        
        int min_idx = i;
        for(int j = i+1; j < B.size(); j++){
            
            if( B[j]->surname < B[min_idx]->surname ) min_idx = j;
        }

        Contact_Str aux = B[i];
        B[i] = B[min_idx];
        B[min_idx] = aux;

    }  
}

int FindPos(const PhoneBook& r, std::string S){
    int mid;
    bool found = false;
    int last = r.size() - 1;
    int first = 0;

    while( first <= last && !found){

        mid = ( first + last) / 2;
        if( r[ mid ]->surname == S ) found = true;
        else
            if( S < r[mid]->surname ) last = mid - 1;
            else
                first = mid + 1;
    }

    if( found ) return mid;
    else return last;
}


void Shift_PhoneBook(PhoneBook& B, int pos){
    
    B.resize( (B.size()+1) );
    for(int i= B.size()-1; i > pos; i--) B[i] = B[i-1];
}

bool add_ord(PhoneBook& B, std::string surname, std::string name, long int phoneNumber){
    
    //devo inserire nella posizione dopo
    int pos = FindPos(B, surname);

    Shift_PhoneBook(B,pos+1);
    pos= pos+1;

    Contact_Str C = new Contact_Str_Impl;
    C->name = name;
    C->surname = surname;
    C->phone = phoneNumber;
    
    B[pos] = C;

    std::cout << "Phone: " << phoneNumber << std::endl << "Phone_B: "<< B[pos]->phone;

    return true;

}
