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
	void dodajOsobe(std::string imie, std::string nazwisko, unsigned long long pesel);
	void usunOsobe();
	int ileOsob();			// funkcja zwracaj�ca ilo�� os�b na naszej li�cie
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

void lista::dodajOsobe(std::string imie, std::string nazwisko, unsigned long long pesel) {
	osoba *nowa = new osoba;
	nowa->imie = imie;
	nowa->nazwisko = nazwisko;
	nowa->pesel = pesel;

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

int lista::ileOsob() {
	int licznik=0;
	osoba *temp = pierwsza;
	if (pierwsza == 0) {
		//std::cout << "\tLista jest pusta\n";
		return 0;
	}
	else {
		while (temp) {
			licznik++;
			temp = temp->nastepna;
		}
		//std::cout << "\tNa liscie jest " << licznik << " osob\n";
		return licznik;
	}
}

void lista::usunOsobe() {
	int number;
	do {
		std::cout << std::endl << "		Deleting person\nnumber of the person you want to delete (1 = first, 2 = second...): ";
		std::cin >> number;
		if (number > ileOsob())
			std::cout << "\n\n\t cos jest nie tak z numerem ktory wpisales. Chyba jest wiekszy niz liczba osob na liscie\n";
	} while (number > ileOsob());

	if (number == 1) {
		pierwsza = pierwsza->nastepna;
	}
	else if (number == 0) {
		std::cout << "Jestes pacyfista? nikogo nie usuniesz\n";
	}
	else if (number == ileOsob() ){
		osoba *temp = pierwsza;
		int licznik = 1;
		while (licznik < (ileOsob() - 1)) {
			temp = temp->nastepna;
			licznik++;
		}
		temp->nastepna = temp->nastepna->nastepna;
	}
	else if (number < ileOsob()) {
		osoba *temp = pierwsza;
		int licznik = 1;
		while (licznik != (number - 1)) {
			temp = temp->nastepna;
		}
		temp->nastepna = temp->nastepna->nastepna;
	}
	else {
		std::cout << "\nniezrozumiale polecenie\n";
	}


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
	baza->dodajOsobe("Marek", "Mikulski", 97030204971);
	baza->dodajOsobe("Agata", "Buksinska", 97101812345);
	baza->dodajOsobe("Karol", "Koala", 89101412345);
	baza->dodajOsobe("Amelia", "Kot", 98071912345);

	baza->wyswietlListe();
	std::cout<<"\nNa liscie jest "<<baza->ileOsob()<<" osob";

	baza->usunOsobe();

	std::cout << "\nNa liscie jest " << baza->ileOsob() << " osob";
	baza->wyswietlListe();

	system("pause");
	delete baza;
	return 0;
}