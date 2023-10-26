#pragma once
//using namespace std;
class Ustawienia
{
	bool Opcje[8] = { 1,0,1,1,0,0,1,0 };
	/*
	Ustawienia() { Opcje[0] = 1, Opcje[1] = 0, Opcje[2] = 1, Opcje[3] = 1, Opcje[4] = 0, Opcje[5] = 0, Opcje[6] = 1, Opcje[7] = 0; }
	Ustawienia() { ; }
	~Ustawienia(){}
	*/
public:
	void wyswietl() {
		std::cout << "=============================" << std::endl << "MENU OPCJI" << std::endl;
		std::cout << std::endl << "Aktywne opcje:" << std::endl;
		for (int i = 0; i < 8; i++) {
			if (Opcje[i]) {
				std::cout << "Opcja " << i << " jest aktywna" << std::endl;
			}
		}
		std::cout << std::endl << "Pozosta³e opcje:" << std::endl;
		for (int i = 0; i < 8; i++) {
			if (Opcje[i]==0) {
				std::cout << "Opcja " << i << " jest nieaktywna" << std::endl;
			}
		}

	}
};

