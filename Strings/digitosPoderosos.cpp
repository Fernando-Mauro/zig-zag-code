#include <bits/stdc++.h> 

using namespace std;

typedef unsigned long long int i64;


i64 suma(string cadena){
    i64 total = 0;

    for(int i = 0; i < cadena.length(); ++i){
        total += cadena[i] - '0';
    }

    return total;
}

string solve(string &original, int times){
    i64 sumaDigitos = i64(suma(original) * i64(times));

    string temp = to_string(sumaDigitos);

    while(temp.length() > 1){
        sumaDigitos = suma(temp);
        temp = to_string(sumaDigitos);
    }

    return temp; 
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    
    while(n--){
        string original;
        int times;
        cin >> original >> times;
        cout << solve(original, times) << "\n";
    }

    return 0;
}