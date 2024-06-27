// https://omegaup.com/arena/problem/La-Tiendita-de-don-Alberto//
#include <bits/stdc++.h>

using namespace std;

int main(){
    map <int, int> inventario;

    for(int i = 0; i < 5; ++i){
        int n;
        cin >> n;
        while(n--){
            int clave, cantidad;
            cin >> clave >> cantidad;
            
            inventario[clave] += cantidad;
        }
    }
    
    for(auto i:inventario){
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}