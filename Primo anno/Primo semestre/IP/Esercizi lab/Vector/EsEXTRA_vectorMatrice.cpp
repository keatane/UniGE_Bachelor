// Vector di vector (matrice)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int r = 3, c = 3;
    vector < vector<int> > v;
    vector <int> v1;
	
	// Inserisco un vector vuoto per ogni riga
    for(int i=0;i<r;i++){
        v.push_back(v1);
    }

	// Inserisco un intero in ogni posizione del vector di interi (colonne) per ogni colonna, tutto per ogni riga
	// N.B v è un vector di vector (è un array di vector), v[i] è un "elemento" in posizione i di v, ovvero un vector di interi
    for(int i=0;i<r;i++){

      for(int j=0;j<c;j++){

        int x;
        cin >> x;
        v[i].push_back(x);
      }
    }
    cout << endl;


	for(int i=0;i<r;i++){

      for(int j=0;j<c;j++){

         cout << v[i][j];
        cout << " ";

      }
      cout << endl;
   }
}
