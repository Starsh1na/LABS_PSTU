#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, ".65001");
    
    double a = 0.1, b = 1.0;
    int k_steps = 10;
    double h = (b - a) / k_steps;
    double eps = 0.0001;
    
    cout << fixed << setprecision(4);
    cout << "--------------------------------------------------------\n";
    cout << "|    X    |    SN   |    SE   |    Y    |" << endl;
    cout << "--------------------------------------------------------\n";
    
    
    for (double x = a; x <= b + h / 2.0; x += h) {
        double sn = 1.0; 
        double se = 1.0; 
        double ak = 1.0; 
        
        
        for (int k = 1; k <= k_steps; k++) {
            ak = ak * (2.0 * k + 1.0) / ((2.0 * k - 1.0) * k) * x * x;
            sn += ak;
        }
        
        
        ak = 1.0; 
        int k = 1;
        while (abs(ak) >= eps) { 
            ak = ak * (2.0 * k + 1.0) / ((2.0 * k - 1.0) * k) * x * x;
            se += ak;
            k++;
        }
        
        
        double y = (1.0 + 2.0 * x * x) * exp(x * x);
        
        
        cout << "| " << setw(6) << x << " | " << setw(6) << sn 
             << " | " << setw(6) << se << " | " << setw(6) << y << " |\n";
    }
    cout << "--------------------------------------------------------\n";
    
    return 0;
}