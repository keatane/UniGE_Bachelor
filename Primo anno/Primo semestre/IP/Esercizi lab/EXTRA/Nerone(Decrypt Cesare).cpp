#include <iostream>

using namespace std;

int main()
{
    string s;
    cout << "Inserisci stringa: ";
    cin >> s;
    cout << endl;

    // Encryption

    // k di shift
    int k = 20;

    for (int i=0; i<s.size(); i++)
    {
        s[i] = s[i] + k;
    }

    cout << "Stringa criptata\n";
    for (int i=0; i<s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    cout << endl;


    // Decryption

    cout << "Una delle seguenti parole sara' quella corretta" << endl;
    k=1;
    for (int j=0; j<26; j++){

        string sCopy = "";
        // Inizializzo alla stringa data
        for (int i=0; i<s.size(); i++)
        {
            sCopy[i] = s[i];
        }

        for (int i=0; i<s.size(); i++)
        {
            // Controllo se un carattere va prima di a e lo porto a z
            for (int h=0; h<k; h++)
            {
                sCopy[i] = sCopy[i] - 1;
                if (sCopy[i] < 'a') sCopy[i] = 'z';
            }
        }

        for (int i=0; i<s.size(); i++)
        {
            cout << sCopy[i] << " ";
        }
        cout << endl;
        k++;
    }
}



