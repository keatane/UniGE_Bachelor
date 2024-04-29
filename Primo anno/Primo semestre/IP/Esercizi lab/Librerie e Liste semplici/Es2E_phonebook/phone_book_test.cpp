#include "phone_book.h"

int main(){

    std::vector<Contact_Str> B;

    add(B, "Rossi", "Mario", 341253654);
    add(B, "Garibaldi", "Giuseppe", 331253654);
    add(B, "Novara", "Edoardo", 32123154);
    add(B, "Leopardi", "Giacomo", 34553654);

    print(B);
    
    
    std::cout << "\n\nSorting the PhoneBook...\n\n";
    sortSurnames(B);
    print(B);

    std::cout << "\n\nFind Novara in the PhoneBook...\n\n";
    std::cout << "\n\n Novara is the number "<<FindPos(B,"Novara") + 1 << " of the PhoneBook\n\n";


    std::cout << "\n\nFind Othello in the PhoneBook...\n\n";
    std::cout << "\n\n The previous surname respet to Othello is the number "<<FindPos(B,"Othello") + 1 << " of the PhoneBook\n\n";

    std::cout << "\n\nResize the PhoneBook, shift the element and insert the new contact in order...\n\n";
    add_ord(B, "Motta", "Piero", 330395314 );
    print(B);

}