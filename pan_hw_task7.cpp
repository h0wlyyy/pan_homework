// pan_hm_task7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	double acc;
	string message_1 = "Летательный аппарат находится в режиме набора высоты";
	string message_2 = "Летательный аппарат находится в режиме горизонтального полета";
	string message_3 = "Летательный аппарат находится в режиме снижения";

	setlocale(LC_ALL, "Russian");
	cout << "Введите ускорение: ";
	cin >> acc;

	if (acc > 0.5) {
		cout << message_1;
		return 0;

	}
	else if (0 < acc < 0.5) {
		cout << message_2;
		return 0;
	}
	else if (acc < 0) {
		cout << message_3;
		return 0;
	}
	else {
		cout << "что то не так";
		return 1;
	}
	


}
