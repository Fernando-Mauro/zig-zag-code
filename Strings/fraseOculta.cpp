#include <bits/stdc++.h> 

using namespace std;

int descifrar(int submulti, string frase){
    vector <int> sumas(submulti);

    for(int i = 0; i <= submulti; ++i){
        for(int j = i; j < frase.size(); j += submulti){
            char upper = toupper(frase[j]);
            sumas[i] += upper - 64;
        }
    }
    
    int total = 1;
    for(int i = 0; i < submulti;++i){
        total *= (sumas[i] % 10) + 1;
    }
    
    return (total % 10) + 1;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string frase;
    char trash;
    int submulti;
    cin >> trash >> submulti >> frase;

    cout << descifrar(submulti, frase) << "-";
    
    cin >> trash >> submulti >> frase;
    cout << char(descifrar(submulti, frase) + 64);
    
    return 0;
}