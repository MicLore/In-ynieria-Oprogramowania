#include <iostream>
#include "funkcje.h"

using namespace std;
double sumator=0;
int main()
{
	double tab[20];
	for (int i = 0; i < 20; i++) {
		tab[i] = 20 - (i/2);
	}
	cout << "Wartość logarytmu z 3: "<<logarytm(3)<<endl;
	cout << "Wartość eksponentu z 9: " << eksponent(9) << endl;
	cout << "warotść odchylenia: " << odchylenie(tab,sumator) << endl;
	cout << "warotść dzielenia 4 przez 7: " << dzielenie(4, 7) << endl;
}