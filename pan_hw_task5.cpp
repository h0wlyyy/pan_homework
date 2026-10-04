// pan_hw_task5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iostream>
#include <clocale>
using namespace std;


struct plane {
    string name;      
    double m;     
    double S;         
    double T;         
    double C_D;       
    double C_L;       
};


double L_calc(double rho, double V, double S, double C_L) {
    return 0.5 * rho * V * V * S * C_L;
}

double resistance(double rho, double V, double S, double C_D) {
    return 0.5 * rho * V * V * S * C_D;
}

double A_calc(double L, double D, double T, double m, double g = 9.81) {
    
    return (T - D + L - m * g)/m;
    
}

int main() {
    setlocale(LC_ALL, "Russian");
    plane planes[3];

    planes[0] = { "Самолёт 1", 5200,  32.5, 55000, 0.06, 0.51 };
    planes[1] = { "Самолёт 2", 11500,  41.1, 76000, 0.14, 0.69 };
    planes[2] = { "Самолёт 3", 7000,  24.0, 37000, 0.01555, 0.65 };

    double rho = 1.225;  
    double V = 280.0;  
    double h = 2000.0; 
    double best_time = 1e18;  
    int best_index = -1;

    for (int i = 0; i < 3; i++) {
        double L = L_calc(rho, V, planes[i].S, planes[i].C_L);
        double D = resistance(rho, V, planes[i].S, planes[i].C_D);
        double a = A_calc(L, D, planes[i].T, planes[i].m);
        
        if (a > 0) {
            double t = sqrt(2 * h / a);
            if (t < best_time) {
                best_time = t;
                best_index = i;
            }
        }
        else {
            cout << " Ошибка (ускорение <= 0)" << endl;
        }
        cout << endl;
    }
    if (best_index != -1) {
        cout << "Быстрее всех наберёт высоту: " << planes[best_index].name
            << " за " << best_time << " с" << endl;
    }

    return 0;
}