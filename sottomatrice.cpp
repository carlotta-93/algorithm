#include <iostream>
#include <fstream>

using namespace std;



int main () {
	fstream ingresso, uscita;
	int temporaneo = 0;
	int sommatotale = 0;
	int righe, colonne;
	
	ingresso.open("input.txt", ios::in);
	uscita.open("output.txt", ios::out);
	
	ingresso >> righe >> colonne;

	// alloco matrice
	int** matrice = new int*[righe];

    for (int i=0; i<righe; i++)
          matrice[i] = new int[colonne];

	// prendo la matrice in input dal file 
    for(int i=0; i<righe; i++)
        for(int j=0; j<colonne; j++)
            ingresso >> matrice[i][j];

        // per ogni riga devo creare u array con la somma massima dei suoi elementi
	int *arraySomma = new int[colonne];
	
	for (int k=0; k<righe; k++){
	
		for(int j=0; j<colonne; j++)
            arraySomma[j] = 0;
	
		for (int y=k; y<righe; y++){
	
	        int somma = 0;
			for (int i = 0; i<colonne; ++i)
			{
				arraySomma[i] = arraySomma[i] + matrice[y][i] ;
				somma = max(somma + arraySomma[i], 0);
				temporaneo = max(somma, temporaneo);
			}
			sommatotale = max(temporaneo, sommatotale);
		}
	}
	
	uscita << sommatotale << endl;

	ingresso.close();
	uscita.close();
	return 0;

}