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
	void dodajOsobe(std::string imie, std::string nazwisko, unsigned long long pesel);
	void usunOsobe();
	int ileOsob();			// funkcja zwracaj¹ca iloœæ osób na naszej liœcie
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

void lista::dodajOsobe(std::string imie, std::string nazwisko, unsigned long long pesel) {
	osoba *nowa = new osoba;
	nowa->imie = imie;
	nowa->nazwisko = nazwisko;
	nowa->pesel = pesel;

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
		else if (number < 0)
			std::cout << "\n\n\t Nie no stary... nie mozesz usunac ujemnej ilosci ludzi. Jak nie chcesz nikogo usuwac to wpisz zero.\n";
	} while (number > ileOsob() || number<0);

	if (number == 1) {
		pierwsza = pierwsza->nastepna;
	}
	else if (number == 0) {
		std::cout << "Brawo! Otrymujesz pokojowego nobla za nie usuniecie nikogo\n";
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

	lista *baza = new lista;		// tworzê listê

	int wybor;
	do{
	system("cls");
	std::cout << "   ----=== ONE WAY LIST ===----  " << std::endl;
	std::cout << "   1. Add a person to your list  " << std::endl;
	std::cout << "   2. Delete person from your list  " << std::endl;
	std::cout << "   3. Display your list  " << std::endl;
	std::cout << "   4. Check the number of people on your list  " << std::endl;
	std::cout << "   5. Automaticly adding 4 people to your list  " << std::endl;
	std::cout << "   6. Credits  " << std::endl;
	std::cout << "   0. Exit  " << std::endl;
	std::cout << "   ------- ---- -------  " << std::endl;
	std::cout << "What would you like to do? :";

	std::cin >> wybor;

	if (wybor == 1)
	{
		system("cls");
		baza->dodajOsobe();
		
	}
	else if (wybor == 2)
	{
		system("cls");
		baza->usunOsobe();
		
	}
	else if (wybor == 3)
	{
		system("cls");
		baza->wyswietlListe();
		system("pause");
	}
	else if (wybor == 4)
	{
		std::cout << "\nNa liscie jest " << baza->ileOsob() << " osob\n\n";
		system("pause");
	}
	else if (wybor == 5)
	{
		baza->dodajOsobe("Marek", "Mikulski", 97030204971);
		baza->dodajOsobe("Agata", "Buksinska", 97091812345);
		baza->dodajOsobe("Karol", "Koala", 89101412345);
		baza->dodajOsobe("Amelia", "Kot", 98071912345);
		std::cout << "\n\tDone ;)\n\n";
		system("pause");
	}
	else if (wybor == 6)
	{
		std::cout << "\n\tThis project is BEER-WARE LICENSED:\nThis means you can do whatever you want with this stuff, unless your hurt anybody with that.\nIf we meet some day, and you think this stuff is worth it, you can buy me a beer in return\n\t\t\t\t\t\t\t\t\t\tMarek Mikulski\n\n";
		system("pause");
	}
	else if (wybor != 1 && wybor != 2 && wybor != 3 && wybor != 4 && wybor != 0 && wybor != 5 && wybor != 6)
	{
		std::cout << std::endl << "Glupi jestes? Nie ma takiego numerka w menu" << std::endl;
		system("pause");
	}
} while (wybor != 0);
				/*
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
				*/		
	system("pause");
	delete baza;
	return 0;
}