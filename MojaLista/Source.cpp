#include <iostream>
#include <string>

struct osoba {				// struktura opisuj�ca pojedynczy element listy
	std::string imie;
	std::string nazwisko;
	unsigned long long pesel;
	osoba *nastepna;		//wska�nik na kolejny element listy
	osoba();
};

osoba::osoba() {			// konstruktor struktury "osoba"
	nastepna = 0;			// je�li b�dzie jaki� problem ze wska�nikami to zmie� na NULL
}

struct lista {
	osoba *pierwsza;		// wska�nik na pocz�tek listy (pierwszy element listy)
	void dodajOsobe();		// dodaje osob� na koniec listy
	void usunOsobe();
	// void sortuj();		// to bedzie funkcja sortuj�ca wed�ug daty urodzenia (pierwszych 6 cyfr peselu)
	void wyswietlListe();
	lista();
};

lista::lista() {
	pierwsza = 0;
}

void lista::dodajOsobe() {	// musimy rozpatrzy� 2 przypadki ( gdy dodajemy pierwszy element i gdy 2 lub kolejny)

	osoba *nowa = new osoba;
	std::cout << "	Creating new person\nname: ";
	std::cin >> nowa->imie;
	std::cout << "surname: ";
	std::cin >> nowa->nazwisko;
	do {
		std::cout << "pesel: ";
		std::cin >> nowa->pesel;
		if (nowa->pesel < 00010100000)
			std::cout << "\n\tpesel za maly, jeszcze raz\n";
		else if (nowa->pesel > 99123199999)
			std::cout << "\n\tpesel za duzy, jeszcze raz\n";
		//if (nowa->pesel < 00010100000 || nowa->pesel > 99123199999);
		//	std::cout << "\n	I'm sorry, but there is something wrong with pesel number, please try again\n	(make sure it cantains 2 last digots of birthyear, month number, day number and 5 additional digits)\n";
	} while (nowa->pesel < 00010100000 || nowa->pesel > 99123199999);

	if (pierwsza == 0) {
		pierwsza = nowa;
	}
	else {					// przypadek gdy istanieje ju� pierwsza osoba na li�cie, wi�c w�drujemy na koniec listy i tam dodajemy osob�
		osoba *temp = pierwsza;

		while (temp->nastepna) {	// gdy element posiada wska�nik na nast�pny element to wykonuje:
			temp = temp->nastepna;	// t� p�tl� dochodz� na koniec listy
		}
		temp->nastepna = nowa;
		nowa->nastepna = 0;			// wska�nik na nast�pny element dla ostatniego elementu musi by� -> NULL lub 0
	}
}

void lista::usunOsobe() {

	std::cout << std::endl << "		Deleting person\nnumber of the person you want to delete: ";
	std::cin

}

void lista::wyswietlListe() {

	osoba *temp = pierwsza;
	std::cout << "\n\n		Displaying list";
	while (temp) {
		std::cout << std::endl << temp->imie;
		std::cout << std::endl << temp->nazwisko;
		std::cout << std::endl << temp->pesel << std::endl;
		temp = temp->nastepna;
	}
}

int main() {

	lista *baza = new lista;		// tworz� list�

	baza->dodajOsobe();
	baza->dodajOsobe();
	baza->dodajOsobe();

	baza->wyswietlListe();

	system("pause");
	delete baza;
	return 0;
}