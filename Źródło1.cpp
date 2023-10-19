#include <iostream>
using namespace std;

int main() {
	int AA[10];
	int i = 0;
	int sumator = 0;
	while (i < 10) {
		cin >> AA[i];
		i++;
	}
	for (int g = 0; g < 10; g++) {
		if (AA[g] < 0) {
			sumator++;
		}
	}
	int* BB = new int[sumator];
	i = 0;
	for (int g = 0; g < 10; g++) {
		if (AA[g] < 0) {
			BB[i] = AA[g];
			i++;
		}
	}
	cout << "Liczby ujemne: " << endl;
	for (int g = 0; g < sumator; g++) {
		cout << BB[g] << endl;
	}
	cout << "Liczb ujemnych by³o: " << sumator << " a pominiêto: " << (10 - sumator) << endl;
	delete BB;
}
