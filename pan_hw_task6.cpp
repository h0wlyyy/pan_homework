// pan_hm_task_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <clocale>
#include <iomanip>
#include <cstdlib>  
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double C_l = 0.57;
    double S = 40;
    const int n = 7;
    double velocities[n];
    double rhos[7] = { 1.11, 1.23, 1.24, 1.25, 1.28, 1.32, 1.16 };
    srand(time(0));
    for (int i = 0; i < n; i++) {
        velocities[i] = 40.0 + (double)rand() / RAND_MAX * (450.0 - 40.0);
    }
    for (int i = 0; i < n; i++) {
        cout << i+1 << fixed << setprecision(3) << "   " << velocities[i] << "   " << rhos[i] << "   " << 0.5 * rhos[i] * velocities[i] * velocities[i] * C_l * S <<
            "   " << endl;
    }
    return 0;
}
