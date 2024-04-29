#include <vector> 
#include "ricorsione.h" 


const string menu = "\n\nSi hanno a disposizione 10 registri numerati da 0 a 9. I registri contengono sequenze inizialmente vuote.\nSi selezioni l'operazione scelta e si inseriscano di seguito gli operandi richiesti.\na: lettura di una sequenza di numeri letti da file con inserimento in testa; il file deve essere terminato da -1000000 (2 operandi: nome_file indice_reg); \nb: lettura di una sequenza di numeri da file con inserimento in ordine; il file deve essere terminato da -1000000 (2 operandi: nome_file indice_reg); \nc: lettura di una sequenza da standard input con inserimento in testa (1 operando: indice_reg);\nd: inserimento di un elemento in testa (2 operandi: elem indice_reg); \ne: inserimento ordinato [funziona correttamente solo se la sequenza in cui si inserisce e' ordinata] di un elemento (2 operandi: elem indice_reg);\nf: cancellazione di un elemento da una sequenza (2 operandi: elem indice_reg); \ng: test di appartenenza (2 operandi: elem indice_reg);\nh: cardinalita' di una sequenza (1 operando: indice_reg); \ni: inverte e stampa (1 operando: indice_reg); \nl: stampa (1 operando: indice_reg);\nm: stampa di tutti i registri (0 operandi); \nn: somma e moltiplica i valori nel registro (1 operandi: indice_reg); \no: esiste un elemento minore di quello dato nel registro (2 operandi: elem indice_reg); \np: mostra questo menu;\nq: terminazione.\n\n";

const int maxreg = 10;

int main()
{
try {
vector<seq::Seq> v(maxreg);
for (int j=0; j<maxreg; ++j)  // inizializzo i registri in modo che tutti contengano all'inizio la lista vuota
   seq::createEmpty(v[j]);


seq::Elem e;
int i;
string nome_file;

cout << menu;
cout << "\nDigitare p per stampare il menu, q per terminare\n> ";
char ch;
cin >> ch;
while (ch!='q')
{
   switch(ch)
   {
   case 'a':
   cin >> nome_file;
   if (!cin) throw runtime_error("Errore inserimento nome file\n");
   cin >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   v[i] = seqReadFromFile(nome_file);
   // seqPrint(v[i]);
   break;

   case 'b':
   cin >> nome_file;
   if (!cin) throw runtime_error("Errore inserimento nome file\n");
   cin >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   v[i] = seqOrderedReadFromFile(nome_file);
   // seqPrint(v[i]);
   break;

   case 'c':
   cin >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   v[i] = seqReadFromStdin();
   // seqPrint(v[i]);
   break;


   case 'd':
   cin >> e >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   seq::insertElem(e, v[i]);
   // seqPrint(v[i]);
   break;

   case 'e':
   cin >> e >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   seq::insertElemInOrder(e, v[i]);
   // seqPrint(v[i]);
   break;

   case 'f':
   cin >> e >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   seq::deleteElem(e, v[i]);
   // seqPrint(v[i]);
   break;

   case 'g':
   cin >> e >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   if (seq::member(e, v[i])) cout << "\nAppartiene\n"; else cout << "\nNon appartiene\n";
   // seqPrint(v[i]);
   break;

   case 'h':
   cin >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   cout << "\nDimensione della sequenza " << seq::size(v[i]) << endl;
   // seqPrint(v[i]);
   break;

   case 'i':
   cin >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   cout << "\nSequenza prima della reverse\n"; 
   seqPrint(v[i]);
   // reverse(v[i]);
   // v[i] = reverse2(v[i]);
   v[i] = reverse3(v[i]); 
   cout << "\n\nSequenza dopo la reverse\n"; 
   seqPrint(v[i]);
   break;

   case 'l':
   cin >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   seqPrint(v[i]);
   break;

   case 'm':
   for (int j=0; j<maxreg; ++j)
       {
        cout << "\nSequenza in posizione " << j << endl;
        seqPrint(v[j]);
       }
   break;

   case 'n':
   cin >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   cout << "\nSomma: " << sumRec(v[i]) << endl;
   cout << "\nProdotto: " << multRec(v[i]) << endl;
   break;
 
   case 'o':
   cin >> e >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   if (existsLesserThan(e, v[i])) cout << "\nEsiste\n"; else cout << "\nNon esiste\n";
   // seqPrint(v[i]);
   break;


   case 'p': 
   cout << menu;
   break;

   default: 
   cout << "\nOpzione non valida\n";
   }

cout << "\nDigitare p per stampare il menu, q per terminare\n> ";
cin >> ch;
}
return 0;
} 
catch (runtime_error &msg) 
   {cerr << "Errore a runtime: " << msg.what() << endl;} 
catch (...) 
   {cerr << "Eccezione non riconosciuta\n";}
}
