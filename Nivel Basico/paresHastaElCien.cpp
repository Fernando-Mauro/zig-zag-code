// Programa que saque del 1 al 100 los numeros pares e impares
#include <bits/stdc++.h>

using namespace std;

int main(){
    // for
    // while
    // do while 
    for(int i = 0; i <= 100; i += 1){
        if(i % 2 == 0){
            if(i < 50){
                cout << i << " es par" << endl;
            }else{
                cout << "Ya no quiero mostrar nada >:v";
            }
        }else{
            cout << i << " es impar" << endl;
        }
    }

    // int i = 0;
    // while(i <= 100){
    //     if(i % 2 == 0){
    //         cout << i << " es par" << endl;
    //     }else{
    //         cout << i << " es impar" << endl;
    //     }
    //     i += 1;
    // }

    return 0;
}