#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#define ROZMIAR 8
using namespace std;
//#define ROZMIAR 8	//liczba opcji dostępnych w menu ustawień + 1

class Ustawienia
{
	//int zestawOpcji[ROZMIAR];

public:
	int zestawOpcji[ROZMIAR];

	void menu() {
		system("cls");
		cout << "==========================================" << endl;
		cout << "                 ORGANIZER                " << endl;
		cout << "==========================================" << endl;
		cout << endl;
		cout << "MENU: " << endl;
		cout << "[1] Wyświetl kalendarz" << endl;
		cout << "[2] Zapisane zdarzenia" << endl;
		cout << "[3] Ustawienia" << endl;
		cout << "[ESC] Wyjście" << endl;
		char x = _getch();
		if (x == 27) {
			system("cls");
			cout << "Dziękujemy za korzystanie z naszego organizera  :)" << endl;
			Sleep(1000);
			exit(0);
		}
		else if (x == '3') {
			system("cls");
			wczytajUstawienia();
			wyswietl();
		}
		else {
			system("cls");
			cout << "błąd" << endl;
			Sleep(500);
			menu();
		}
	}

	void wczytajUstawienia() {
		fstream ustawienia;
		ustawienia.open("ustawienia.txt", ios::in);
		
		if (ustawienia.good() == false)
		{
			menu();
		}
		string line;
		int iterator = 0;
		while (getline(ustawienia, line))
		{
			zestawOpcji[iterator] = stoi(line);
			iterator++;
		}
		ustawienia.close();
		/*zestawOpcji[0] = 0;
		zestawOpcji[1] = 3;
		zestawOpcji[2] = 3;
		zestawOpcji[3] = 0;
		zestawOpcji[4] = 3;
		zestawOpcji[5] = 0;
		zestawOpcji[6] = 3;
		zestawOpcji[7] = 3;*/
	}

	void zapiszUstawienia() {
		/*for (int i = 0; i < ROZMIAR; i++) {
			if (zestawOpcji[i] == 1) {
				zestawOpcji[i] = 0;
			}
			else if (zestawOpcji[i] == 2) {
				zestawOpcji[i] = 3;
			}
		}*/
		fstream ustawienia;
		ustawienia.open("ustawienia.txt", ios::out);
		for (int i = 0; i < ROZMIAR; i++) {
			ustawienia << zestawOpcji[i];
			ustawienia << char(10);
		}
		ustawienia.close();
	}


	void wyswietl() {
		cout << "Ustawienia" << endl << endl;
		for (int i = 0; i <= ROZMIAR; i++) {

			switch (zestawOpcji[i])
			{
			case 0:
				cout << "[ ] Opcja nr. " << i + 1 << endl;
				break;
			case 1:
				cout << "[-] Opcja nr. " << i + 1 << endl;
				break;
			case 2:
				cout << "[*] Opcja nr. " << i + 1 << endl;
				break;
			case 3:
				cout << "[X] Opcja nr. " << i + 1 << endl;
				break;
			default:
				cout << endl << "Opcje zaznaczone  [X]  są aktywne." << endl;
				cout << "Opcje zaznaczone  [*]  są wybrane do aktywacji." << endl;
				cout << "Opcje zaznaczone  [-]  są wybrane do dezaktywacji." << endl;
				break;
			}
		}
		int x = _getch();

		if (x == 27) {
			system("cls");
			cout << "Czy chcesz zapisać ustawienia?" << endl << " T / N" << endl;
			char tru = _getch();
			if (tru == 't') {
				system("cls");
				zapiszUstawienia();
				cout << "Zapisano ustawienia" << endl;
				Sleep(600);
				system("cls");
				menu();
			}
			else if (tru == 'n') {
				system("cls");
				cout << "Nie zapisano ustawień" << endl;
				Sleep(600);
				system("cls");
				menu();
			}
			else {
				cout << "błąd" << endl;
				Sleep(600);
				system("cls");
				wyswietl();
			}
		}
		else if ((x - 49) == 7) {
			system("cls");
			cout << "Czy posiadasz uprawnienia administratora?" << endl << " T / N" << endl;
			char tru = _getch();
			if (tru == 't') {
				system("cls");
				zmienUstawienie(x - 49);
				cout << "Zmieniono opcję" << endl;
				Sleep(600);
				system("cls");
				wyswietl();
			}
			else if (tru == 'n') {
				system("cls");
				cout << "Nie masz wystarczających uprawnień" << endl;
				Sleep(600);
				system("cls");
				wyswietl();
			}
		}
		else {
			zmienUstawienie(x - 49);
		}
	}
	void zmienUstawienie(int numer) {

		switch (zestawOpcji[numer])
		{
		case 0:
			zestawOpcji[numer] = 2;
			break;
		case 1:
			zestawOpcji[numer] = 3;
			break;
		case 2:
			zestawOpcji[numer] = 0;
			break;
		case 3:
			zestawOpcji[numer] = 1;
			break;
		}
		system("cls");
		//wyswietl();
		zapiszUstawienia();
	}

};

int main()
{
	Ustawienia ust;
	ust.menu();
}
