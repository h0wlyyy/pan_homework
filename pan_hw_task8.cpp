#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Aircraft {
    double m;
    double thrust;
    double C_L;
    double C_D;
    double time;
};

int main() {
    setlocale(LC_ALL, "Russian");

    const int n = 3;
    Aircraft planes[n];
    double h = 1000.0;
    double g = 9.81;
    double rho = 1.225;
    double V = 250.0;
    double S = 30.0;

    for (int i = 0; i < n; i++) {
        cout << "Самолет " << i + 1 << endl;
        cout << "Масса: ";
        cin >> planes[i].m;
        cout << "Тяга: ";
        cin >> planes[i].thrust;
        cout << "C_L: ";
        cin >> planes[i].C_L;
        cout << "C_D: ";
        cin >> planes[i].C_D;

        double L = 0.5 * rho * V * V * S * planes[i].C_L;
        double D = 0.5 * rho * V * V * S * planes[i].C_D;
        double a = (planes[i].thrust - D + L - planes[i].m * g) / planes[i].m;

        if (a > 0) {
            planes[i].time = sqrt(2 * h / a);
        }
        else {
            planes[i].time = -1;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (planes[j].time > planes[j + 1].time) {
                Aircraft temp = planes[j];
                planes[j] = planes[j + 1];
                planes[j + 1] = temp;
            }
        }
    }

    cout << fixed << setprecision(3);
    cout << endl << "Результаты:" << endl;
    for (int i = 0; i < n; i++) {
        if (planes[i].time > 0) {
            cout << "Самолет " << i + 1 << ": время = " << planes[i].time << " с" << endl;
        }
        else {
            cout << "Самолет " << i + 1 << ": не может набрать высоту" << endl;
        }
    }

    return 0;
}