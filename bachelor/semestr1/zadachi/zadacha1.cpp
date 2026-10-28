#include <iostream>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, ".65001");
    
    bool f = false;
    int n,a,i=1;
    cin >> n;
    while((i<=n)&&!f) {
        cin >> a;
        if(a==0) {
            i++;
        } else f=true;
    }
    if(f){
        if(a>0) {
            cout << "Первым встречается положительное число: "<<a;
        } else cout<<"Первым встречается отрицательное число: "<<a;
    }else cout<<"Все числа последовательности = 0";
    
    return 0;
}