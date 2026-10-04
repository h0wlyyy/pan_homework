// pan_hw_task4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double h, a_y;
    cout << "Введите высоту :";
    cin >> h;
    cout << "Введите вертикальное ускорение :";
    cin >> a_y;
    if (h < 0 or a_y < 0) {
        cout << "Вводимые параметры должны иметь значение большее нуля!" << endl;
        return 1;
            
    }
    double t = sqrt(2 * h / a_y);
    cout << fixed << setprecision(3) << "Небходимое время для набора заданной высоты: " << t << " c" << endl;

}
    

