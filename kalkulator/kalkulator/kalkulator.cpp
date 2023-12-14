#include <iostream>
#include "funkcje.h"

using namespace std;
double sumator;
int main()
{
	double tab[20];
	for (int i = 0; i < 20; i++) {
		tab[i] = 20 - (i/2);
	}
	cout << "Wartość logarytmu z 3: "<<logarytm(3)<<endl;
	cout << "Wartość eksponentu z 9: " << eksponent(9) << endl;
	cout << "warotść odchylenia: " << odchylenie(tab,sumator) << endl;
}