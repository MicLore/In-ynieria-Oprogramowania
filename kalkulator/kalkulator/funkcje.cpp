
#include "funkcje.h"
using namespace std;
double logarytm(int a) {
	return log(a);
}
double eksponent(int a) {
	return exp(a);
}

double odchylenie(double* tab, double sumator) {
    int i;
    double sa;
    double dodaj = 0, sum = 0;
    double odchylenie = 0;
    for (i = 0; i < 20; i++) {
        
        sumator = sumator+ tab[i];

    }
    sa =sumator / 20;

    for (int i = 0; i < 20; i++)
    {
        dodaj = (tab[i] - sa) * (tab[i] - sa);
        sum += dodaj;
    }

    odchylenie = sqrt(sum / 20);
    return odchylenie;
}