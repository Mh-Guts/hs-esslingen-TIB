//Themen:

//Ein - / Ausgabe, Schleifen, Arrays
//Ihre Aufgabe :

//Schreiben Sie ein Programm, das den Nutzer fragt, wie viele ganze Zahlen eingelesen werden sollen(maximal 10).Lesen Sie dann die gewünschte Anzahl von ganzen Zahlen in ein Array ein.Geben Sie alle Zahlen im Array sowie deren Durchschnitt aus.

//Wenn 3 Zahlen eingegeben werden sollen und die Zahlen 1, 3 und 6 eingegeben werden, muss die Ausgabe folgendermaßen aussehen :

//Anzahl eingeben :
//Zahl eingeben :
//Zahl eingeben :
//Zahl eingeben :
//Zahl[0] : 1
//Zahl[1] : 3
//Zahl[2] : 6
//Durchschnitt : 3.33333

//Code : 


#include <iostream>


int main(int argc, char* argv[])
{
	int Anzahl;
	double ergebnis = 0.0;




	//Zahl soll im Bereich liegen in dem es gültig ist

	do {
		std::cout << "Anzahl eingeben: ";
		std::cin >> Anzahl;
	} while (Anzahl <= 0 || Anzahl > 10);

	int zahlen[10];
	//Zahlen werden eingelesen und summe wird hier berechnet
	for (int i = 0; i < Anzahl; ++i) {
		std::cout << "\n""Zahl eingeben:";
		std::cin >> zahlen[i];
		ergebnis += zahlen[i];
	}

	ergebnis /= Anzahl;

	std::cout << std::endl;

	for (int i = 0; i < Anzahl; ++i) {
		std::cout << "Zahl[" << i << "]: " << zahlen[i] << std::endl;
	}

	std::cout << "Durchschnitt: " << ergebnis << std::endl;



	return 0;
}

