#include <bits/stdc++.h> 

using namespace std;

typedef unsigned long long int i64;

char decimalString(){
    i64 decimal = 0;
    cin >> decimal;
    string cadena = "";
    while(decimal != 0){
        decimal -= 1;
        int res = decimal % 26;
        decimal /= 26;
        cadena.push_back(char(res + 65));
    }
    for(int i = (cadena.size() - 1); i >=0; --i){
        cout << cadena[i];
    }
    return 0;
}

i64 stringDecimal(){
    string varchar;
    cin.ignore();
    getline(cin, varchar);
    i64 suma = 0;
    int power = 0;
    for(int i = (varchar.size() - 1); i >= 0; --i){
        int value = int(varchar[i]) - 64;
        suma += (value * pow(26, power));
        power++;
    }
    return suma;
}

int main(){
    bool type;
    cin >> type;
    switch(type){
        case true: cout << stringDecimal(); break;
        case false: decimalString(); break;
    }
    return 0;
}