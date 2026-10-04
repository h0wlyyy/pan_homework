// pan_hw_task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;
double	horz_a(double T, double D, double m)
{
	return abs((T - D) / m);
}
double	vert_a(double L, double m, double g = 9.81)
{
	return (L - m * g) / m;
}

int main()
{
    setlocale(LC_ALL, "Russian");
	double  L, m, D, T;
	cout << "Введите подъемную силу :";
	cin >> L;
	cout << "Введите массу :";
	cin >> m;
	cout << "Введите  сопротивление :";
	cin >> D;
	cout << "Введите величину тяги двигателя :";
	cin >> T;
	double a_h = horz_a(T, D, m);
	double a_v = vert_a(L, m);

	cout << fixed << setprecision(3) << "Ускорение по ходу движения(то есть его модуль) : " << a_h << "M/c^2" << endl;
	cout << fixed << setprecision(3) << "Вертиальное ускорение : " << a_v << "M/c^2" << endl;
	return 0;

}


