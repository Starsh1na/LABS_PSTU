#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, ".65001");
    
    double epsilon = 1e-4;
    double sum = 0.0;
    double an = 1.0;
    int n = 1;
    
    while (an >= epsilon) {
        sum = sum + an;
        n = n + 1;
        an = tgamma(n + 1) / pow(n, n);
    }
    
    cout << "Сумма ряда = " << sum << endl;
    
    return 0;
}
