#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double  S;
	double V;
	double rho;
	double C_l;
	cout << "Введите площадь (м^2) :";
	cin >> S;
	cout << "Введите скорость (м/c) :";
	cin >> V;
	cout << "Введите коэффициент подъемной силы :";
	cin >> C_l;
	cout << "Введите плотность воздуха(кг/м^3) :";
	cin >> rho;
	double L = 0.5 * S * C_l * V * V * rho;
	cout << fixed << setprecision(3) << "Подъемная сила самолета с данными параметрами:" << L << " H" << endl;
	return 0;
	

}