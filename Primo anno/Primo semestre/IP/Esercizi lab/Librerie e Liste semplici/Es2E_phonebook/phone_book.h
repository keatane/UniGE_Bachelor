#ifndef PHONEBOOK
#define PHONEBOOK

#include <vector>
#include <iostream>

/*typedef struct Contact_Str_Impl{

    std::string name;
    std::string surname;
    long int phone;

}Contact_Str;
*/

typedef struct Contact_Str_Impl *Contact_Str;

typedef std::vector<Contact_Str> PhoneBook;

void add(PhoneBook& B, std::string surname, std::string name, long int phoneNumber);

void print(const PhoneBook& B);

void sortSurnames(PhoneBook& B);

int FindPos(const PhoneBook& r, std::string S);

void Shift_PhoneBook(PhoneBook& B, int pos);

bool add_ord(PhoneBook& B, std::string surname, std::string name, long int phoneNumber);

#endif