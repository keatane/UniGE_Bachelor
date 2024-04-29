// Es_1 a,b,c,d,e di riscaldamento.

#include <iostream>

using namespace std;

void hello(){
	cout << "Hello" << endl;
}

void hellomany (int n){
	cout << "Hello we are " << n << endl;
}

int givemefive(){
	return 5;
}

int prossimo(int n){
	return n+1;
}

int somma(int a, int b){
	return a+b;
}


int main()
{
	hello();
   cout << "Inserisci un numero intero" << endl;
   int num;
   cin >> num;
   hellomany(num);
   cout << "Dammi il cinque! " << givemefive() << endl;
   cout << "Dopo " << num << " c'e' " << prossimo(num) << endl;
   cout << "Somma num+5 = " << somma(num,5) << endl;
}
