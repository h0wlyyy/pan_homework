#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double m, S, C_L, C_D, h;
    double T_min, T_max, dT;
    double rho = 1.225;
    double V = 250.0;
    double g = 9.81;

    cout << "Масса: ";
    cin >> m;
    cout << "Площадь крыла: ";
    cin >> S;
    cout << "C_L: ";
    cin >> C_L;
    cout << "C_D: ";
    cin >> C_D;
    cout << "Высота h: ";
    cin >> h;
    cout << "T_min: ";
    cin >> T_min;
    cout << "T_max: ";
    cin >> T_max;
    cout << "dT: ";
    cin >> dT;

    double L = 0.5 * rho * V * V * S * C_L;
    double D = 0.5 * rho * V * V * S * C_D;

    double best_T = 0;
    double min_time = 1e18;

    cout << fixed << setprecision(3);
    cout << endl;

    for (double T = T_min; T <= T_max; T += dT) {
        double a = (T - D + L - m * g) / m;

        if (a > 0) {
            double t = sqrt(2 * h / a);
            cout << "T = " << T << "  a = " << a << "  t = " << t << endl;

            if (t < min_time) {
                min_time = t;
                best_T = T;
            }
        }
    }

    cout << endl;
    cout << "Оптимальная тяга: " << best_T << endl;
    cout << "Минимальное время: " << min_time << endl;

    return 0;
}