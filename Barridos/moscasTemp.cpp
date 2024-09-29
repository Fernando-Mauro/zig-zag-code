#include <bits/stdc++.h> 

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int moscas;
    int moscasMax = 0; 
    
    cin >> moscas;

    vector <int> linea(60001, 0);

    while(moscas--){
        int nacimiento, muerte;
        cin >> nacimiento >> muerte;
        
        for(int i = nacimiento; i < muerte; ++i){
            linea[i]++;
            // si linea del tiempo en i es mayor que moscasMax entonces moscasMax = linea[i]
            moscasMax = max(moscasMax, linea[i]);
        }
    }

    cout << moscasMax << "\n";

    for(int i = 0; i < linea.size(); ++i){
        if(linea[i] == moscasMax){
            cout << i << " ";
            int j;
            for(j = i + 1;linea[j] == moscasMax; ++j){

            }
            cout << j << "\n";
            i = j - 1;
        }
    }

    return 0;
}