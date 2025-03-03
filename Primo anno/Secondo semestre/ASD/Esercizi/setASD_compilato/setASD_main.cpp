// Cambiando l'header che includiamo nel main e compilando solo il file ausiliario corretto usiamo implementazioni diverse dello stesso TDD insieme
// Si noti che il main non cambia anche se cambiamo l'implementazione del TDD, perché il main "non sa" come è stato implementato il TDD, ma solo quali operazioni mette a disposizione (information hiding)
// Compilare con g++ -ansi -Wall  setASD-ptr_aux.cpp setASD_main.cpp -o  setASD-ptr  per l'implementazione con puntatori
// Compilare con g++ -ansi -Wall  listASD-array_aux.cpp setASD-array_aux.cpp setASD_main.cpp -o  setASD-array  per l'implementazione con array
// Compilare con g++ -ansi -Wall  setASD-vector_aux.cpp setASD_main.cpp -o  setASD-vector  per l'implementazione con vector
// Ricordarsi di commentare/decommentare l'include dell'header giusto

//#include "setASD-vector.h" 
#include "setASD-ptr.h" 
// #include "setASD-array.h" 


const string menu = "\n\nSi hanno a disposizione 10 registri numerati da 0 a 9. I registri contengono degli insiemi (inizialmente vuoti).\nSi selezioni l'operazione scelta e si inseriscano di seguito gli operandi richiesti.\na: lettura di un insieme da file terminato da -1000000 (2 operandi: nome_file indice_reg_in_cui_inserire_insieme_letto);\nb: lettura di un insieme da standard input (1 operando: indice_reg_in_cui_inserire_insieme_letto);\nc: inserimento di un elemento in un insieme, operazione stateful (2 operandi: elem indice_insieme_da_modificare);\nd: inserimento di un elemento in un insieme, operazione funzionale (3 operandi: elem indice_insieme_in_cui_inserire indice_risultato);\ne: cancellazione di un elemento da un insieme, operazione stateful (2 operandi: elem indice_insieme_da_modificare);\nf: cancellazione di un elemento da un insieme, operazione funzionale (3 operandi: elem indice_insieme_da_cui_togliere indice_risultato);\ng: unione insiemi, operazione funzionale (3 operandi: indice_ins_1 indice_ins_2 indice_unione);\nh: intersezione insiemi, operazione funzionale (3 operandi: indice_ins_1 indice_ins_2 indice_intersezione);\ni: test di emptyness (1 operando: indice_insieme);\nl: test di appartenenza (2 operandi: elem indice_insieme);\nm: stampa (1 operando: indice_insieme);\nn: stampa di tutti i registri (0 operandi);\nx: difference (2 operandi: insieme_base, insieme_che_sottrae, indice_registro_insieme_risultato);\ny: subset(2 operandi: potenziale_sottoinsieme, insieme_base, indice_registro_insieme_risultato);\np: mostra questo menu;\nq: terminazione.\n\n";

const int maxreg = 10;

int main()
{
try {
vector<set::Set> v(maxreg);
for (int j=0; j<maxreg; ++j)  // inizializzo i registri in modo che tutti contengano all'inizio l'insieme vuoto
   set::createEmpty(v[j]);


set::Elem e;
int i, j, k;
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
   v[i] = setReadFromFile(nome_file);
   setPrint(v[i]);
   break;


   case 'b':
   cin >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   v[i] = setReadFromStdin();
   setPrint(v[i]);
   break;


   case 'c':
   cin >> e >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   // set::insertElemS(e, v[i]);
   set::insertElemInOrderS(e, v[i]);
   setPrint(v[i]);
   break;


   case 'd':
   cin >> e >> i >> j;
   if (i<0 || i>=maxreg || j<0 || j>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   v[j] = set::insertElem(e, v[i]);
   cout << "\nInsieme in posizione " << i; setPrint(v[i]);
   cout << "\nInsieme in posizione " << j; setPrint(v[j]);
   break;

   case 'e':
   cin >> e >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   set::deleteElemS(e, v[i]);
   setPrint(v[i]);
   break;

   case 'f':
   cin >> e >> i >> j;
   if (i<0 || i>=maxreg || j<0 || j>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   v[j] = set::deleteElem(e, v[i]);
   cout << "\nInsieme in posizione " << i; setPrint(v[i]);
   cout << "\nInsieme in posizione " << j; setPrint(v[j]);
   break;

   case 'g':
   cin >> i >> j >> k;
   if (i<0 || i>=maxreg || j<0 || j>=maxreg || k<0 || k>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   v[k] = set::setUnion(v[i], v[j]);
   cout << "\nInsieme in posizione " << i; setPrint(v[i]);
   cout << "\nInsieme in posizione " << j; setPrint(v[j]);
   cout << "\nInsieme in posizione " << k; setPrint(v[k]);
   break;
 
   case 'h':
   cin >> i >> j >> k;
   if (i<0 || i>=maxreg || j<0 || j>=maxreg || k<0 || k>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   v[k] = set::setIntersection(v[i], v[j]);
   cout << "\nInsieme in posizione " << i; setPrint(v[i]);
   cout << "\nInsieme in posizione " << j; setPrint(v[j]);
   cout << "\nInsieme in posizione " << k; setPrint(v[k]);
   break;

   case 'i':
   cin >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   cout << "\nInsieme in posizione " << i;
   if (set::isEmpty(v[i])) cout << " vuoto\n"; else cout << " pieno\n";
   setPrint(v[i]);
   break;

   case 'l':
   cin >> e >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   if (set::member(e, v[i])) cout << "\nAppartiene\n"; else cout << "\nNon appartiene\n";
   setPrint(v[i]);
   break;

   case 'm':
   cin >> i;
   if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   setPrint(v[i]);
   break;

   case 'n':
   for (int i=0; i<maxreg; ++i)
       {
        cout << "\nInsieme in posizione " << i;
        setPrint(v[i]);
       }
   break;

   case 'p': 
   cout << menu;
   break;
   
   // Caso di esercizio: difference
   case 'x':
   cin >> i >> j >> k;
   if (i<0 || i>=maxreg || j<0 || j>=maxreg || k<0 || k>=maxreg) {cout << "\nIndice fuori range\n"; break;}
   v[k] = set::setDifference(v[i], v[j]);
   cout << "\nInsieme in posizione " << i; setPrint(v[i]);
   cout << "\nInsieme in posizione " << j; setPrint(v[j]);
   cout << "\nInsieme in posizione " << k; setPrint(v[k]);
   break;

	// Caso di esercizio: subset
	case 'y':
	cin >> i >> j;
	if (i<0 || i>=maxreg) {cout << "\nIndice fuori range\n"; break;}
	if (set::isSubset(v[i], v[j])) cout << "\nE' sottoinsieme\n"; else cout << "\nNon è sottoinsieme\n";
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

