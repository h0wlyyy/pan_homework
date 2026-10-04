// pan_hw_task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;

double resistance(double S, double V, double C_D, double rho)
{
	return  0.5 * S * C_D * V * V * rho;
	
}
int main()
{
	setlocale(LC_ALL, "Russian");
	double  S, V, rho, C_D;
	cout << "Введите площадь (м^2) :";
	cin >> S;
	cout << "Введите скорость (м/c) :";
	cin >> V;
	cout << "Введите коэффициент сопротивления :";
	cin >> C_D;
	cout << "Введите плотность воздуха(кг/м^3) :";
	cin >> rho;
	double L = resistance(S, V, C_D, rho);
	cout << fixed << setprecision(3) << "Коэффициент сопротивления " << L << " H" << endl;
	return 0;
}
