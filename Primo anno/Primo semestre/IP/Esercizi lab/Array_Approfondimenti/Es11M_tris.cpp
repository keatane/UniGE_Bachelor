/* Es_11 di base: Scrivere un programma che implementi il gioco del tris. La matrice di gioco dovrà essere rappresentata da una matrice 3x3.
Implementare il gioco in modo tale che giochino 2 umani uno contro l’altro, alternativamente
*/

#include <iostream>

using namespace std;

const int N = 3;
const int M = 3;

struct array2D {
	char data[N][M];
};

int victory(array2D& arr){

    int vittoria = 0;
    // Orizzontale
		if (arr.data[0][0] == 'x' && arr.data[0][1] == 'x' && arr.data[0][2] == 'x')
			vittoria = 1;
		if (arr.data[1][0] == 'x' && arr.data[1][1] == 'x' && arr.data[1][2] == 'x')
			vittoria = 1;
		if (arr.data[2][0] == 'x' && arr.data[2][1] == 'x' && arr.data[2][2] == 'x')
			vittoria = 1;

		if (arr.data[0][0] == 'o' && arr.data[0][1] == 'o' && arr.data[0][2] == 'o')
			vittoria = 2;
		if (arr.data[1][0] == 'o' && arr.data[1][1] == 'o' && arr.data[1][2] == 'o')
			vittoria = 2;
		if (arr.data[2][0] == 'o' && arr.data[2][1] == 'o' && arr.data[2][2] == 'o')
			vittoria = 2;

		// Verticale
		if (arr.data[0][0] == 'x' && arr.data[1][0] == 'x' && arr.data[2][0] == 'x')
			vittoria = 1;
		if (arr.data[0][1] == 'x' && arr.data[1][1] == 'x' && arr.data[2][1] == 'x')
			vittoria = 1;
		if (arr.data[0][2] == 'x' && arr.data[1][2] == 'x' && arr.data[2][2] == 'x')
			vittoria = 1;

		if (arr.data[0][0] == 'o' && arr.data[1][0] == 'o' && arr.data[2][0] == 'o')
			vittoria = 2;
		if (arr.data[0][1] == 'o' && arr.data[1][1] == 'o' && arr.data[2][1] == 'o')
			vittoria = 2;
		if (arr.data[0][2] == 'o' && arr.data[1][2] == 'o' && arr.data[2][2] == 'o')
			vittoria = 2;

		// Diagonale
		if (arr.data[0][0] == 'x' && arr.data[1][1] == 'x' && arr.data[2][2] == 'x')
			vittoria = 1;
		if (arr.data[2][0] == 'x' && arr.data[1][1] == 'x' && arr.data[0][2] == 'x')
			vittoria = 1;

		if (arr.data[0][0] == 'o' && arr.data[1][1] == 'o' && arr.data[2][2] == 'o')
			vittoria = 2;
		if (arr.data[2][0] == 'o' && arr.data[1][1] == 'o' && arr.data[0][2] == 'o')
			vittoria = 2;
    return vittoria;
}

int main()
{
    array2D arr;
    for (unsigned int i=0; i<N; ++i)
			for (unsigned int j=0; j<M; ++j)
                arr.data[i][j] = '0';
	string player1, player2;
	cout << "Inserisci il nome del primo giocatore: ";
	cin >> player1;
	cout << "Inserisci il nome del secondo giocatore: ";
	cin >> player2;
	int i, j;

	cout << player1 << " giocherai col simbolo 'x'\n";
	cout << player2 << " giocherai col simbolo 'o'\n";
	cout << endl;

    int win = 0;
	do{
        bool repeat = false;
		// Player 1
		do{
            repeat = false;
			cout << player1 << " fai la tua mossa\n";
			cout << "Inserisci gli indici (riga,colonna) della posizione nel tris (0,1,2)" << endl;
			cin >> i >> j;

			if (arr.data[i][j] == '0')
				arr.data[i][j] = 'x';
			else{
				cout << "Cella gia' riempita, ripeti:" << endl;
				repeat = true;
			}
		}while (repeat == true);
        win = victory(arr);
        if (win != 0) break;
        cout << endl;
		// Player 2
        do{
            repeat = false;
            cout << player2 << " fai la tua mossa\n";
            cout << "Inserisci gli indici (riga,colonna) della posizione nel tris (0,1,2)" << endl;
            cin >> i >> j;
            if (arr.data[i][j] == '0')
                arr.data[i][j] = 'o';
            else{
                cout << "Cella gia' riempita, ripeti:" << endl;
                repeat = true;
			}
		}while (repeat == true);
        win = victory(arr);
        if (win != 0) break;

		// Controllo l'eventuale griglia piena // (non funzionante)
		bool continueTo = false;
		for (unsigned int k=0; k<N; ++k)
			for (unsigned int h=0; h<M; ++h)
				if (arr.data[k][h] == '0')
					continueTo = true;

        if (continueTo == false){
            cout << "\n---------------------\n";
			cout << "Griglia piena!" << endl;
            return 0;
        }
        continueTo = false;
        cout << endl;
	}while (win == 0);

    cout << "\n---------------------\n";
	if (win == 1)
		cout << "Vince " << player1 << endl;
	else
		cout << "Vince " << player2 << endl;
}
