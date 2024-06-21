// https://www.geeksforgeeks.org/stdgcd-c-inbuilt-function-finding-gcd/

#include <bits/stdc++.h> 

using namespace std;

typedef long long int i64;
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    i64 q, time;
    i64 movs = 0;

    cin >> q >> time;

    while(q--){
        i64 a, b;
        cin >> a >> b;

        if( a == b){
            movs++;
            continue;
        }

        i64 commonDivider = __gcd(a, b);

        // si son primos ambos
        if(commonDivider == 1){
            movs += min(a, b) + 1;
            continue;
        }

        while(a != 0 && b != 0 && (movs - 1) < time){
            a -= commonDivider;
            b -= commonDivider;
            movs++;
            if(a == 0 && b != 0){
                movs++;
                b = 0;
            }
            if(b == 0 && a != 0){
                movs++;
                a = 0;
            }
        }
    }

    if((movs - 1) > time){
        cout << "El Agente A no sera heroe nacional, el Doctor B destruira su pais";
    }else{
        cout << (movs - 1);
    } 
    return 0;
}