#include <iostream>
#include <sstream>
#include <string>
#include "set.h" // implementa liste di interi

using namespace std;

int main()
{
    Set s;
    string linea;
    Base_Type e ;
    char op='X';
    bool fine=false;
    create_empty_set(s);
    
    
    while (!fine) {
    cout << "op (I (insert), E(erase), C (clear), 0 (is empty?), X(exit), ? (is in?), U (union):, N(inters) \n";
        
      std::getline(cin,linea);
      stringstream stream(linea);
        
        
      stream >> op;
        
        switch(op) {
            case 'I':
                stream >> e;
                insert_in_set(e,s);
                break;
            case 'C':
                empty_set(s);
                break;
            case '0':
                cout << (is_empty_set(s) ? "vuoto\n" : "non vuoto\n");
                break;
            case 'X':
                fine=true;
                break;
            default:
                cout << "comando sconosciuto\n";
                break;
            case '?':
                stream >> e;
                cout << (is_in_set(e,s) ? "c'e`\n" : "non c'e`\n");;
                break;
            case 'U':
            {
                Set s_aux;
                create_empty_set(s_aux);
                while (stream >> e) { //costruisco il set ausiliario
                    insert_in_set(e,s_aux);
                }
                s=union_set(s,s_aux);
                empty_set(s_aux);
                break;
            }
            case 'N':
            {
                Set s_aux;
                create_empty_set(s_aux);
                while (stream >> e) { //costruisco il set ausiliario
                    insert_in_set(e,s_aux);
                }
                s=inters_set(s,s_aux);
                empty_set(s_aux);
                break;
            }
       }
        print_set(s);
        
    }
    
}
