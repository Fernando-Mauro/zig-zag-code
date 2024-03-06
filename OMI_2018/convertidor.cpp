#include <bits/stdc++.h> 

using namespace std;

char decimalString(){
}

int stringDecimal(){
    string varchar;
    cin.ignore();
    getline(cin, varchar);
    int suma = 0;
    for(int i = 0; i < varchar.size(); ++i){
        int value = int(varchar[i]) - 64;
        int pos = (varchar.size() - i);
        suma += value * pow(26, pos);
    }
    return suma;
}

int main(){
    bool type;
    cin >> type;
    switch(type){
        case false: cout << stringDecimal(); break;
        case true: decimalString(); break;
    }

    return 0;
}