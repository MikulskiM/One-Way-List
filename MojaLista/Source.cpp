#include <iostream>
#include <string>

struct osoba {				// struktura opisuj¹ca pojedynczy element listy
	std::string imie;
	std::string nazwisko;
	unsigned long long pesel;
	osoba *nastepna;		//wskaŸnik na kolejny element listy
	osoba();
};

osoba::osoba() {			// konstruktor struktury "osoba"
	nastepna = 0;			// jeœli bêdzie jakiœ problem ze wskaŸnikami to zmieñ na NULL
}

struct lista {
	osoba *pierwsza;		// wskaŸnik na pocz¹tek listy (pierwszy element listy)
	void dodajOsobe();		// dodaje osobê na koniec listy
	void usunOsobe();
	// void sortuj();		// to bedzie funkcja sortuj¹ca wed³ug daty urodzenia (pierwszych 6 cyfr peselu)
	void wyswietlListe();
	lista();
};

lista::lista() {
	pierwsza = 0;
}

void lista::dodajOsobe() {	// musimy rozpatrzyæ 2 przypadki ( gdy dodajemy pierwszy element i gdy 2 lub kolejny)

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
	else {					// przypadek gdy istanieje ju¿ pierwsza osoba na liœcie, wiêc wêdrujemy na koniec listy i tam dodajemy osobê
		osoba *temp = pierwsza;

		while (temp->nastepna) {	// gdy element posiada wskaŸnik na nastêpny element to wykonuje:
			temp = temp->nastepna;	// t¹ pêtl¹ dochodzê na koniec listy
		}
		temp->nastepna = nowa;
		nowa->nastepna = 0;			// wskaŸnik na nastêpny element dla ostatniego elementu musi byæ -> NULL lub 0
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

	lista *baza = new lista;		// tworzê listê

	baza->dodajOsobe();
	baza->dodajOsobe();
	baza->dodajOsobe();

	baza->wyswietlListe();

	system("pause");
	delete baza;
	return 0;
}