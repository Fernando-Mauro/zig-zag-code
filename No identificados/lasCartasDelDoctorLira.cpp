#include <bits/stdc++.h> 

using namespace std;


int solve(char init, string &cartas){
    int changes = 0;
    for(int i = 0; i < cartas.length(); i++){
        if(i % 2 == 0){
            if(cartas[i] == init)
                changes++;
        }else{
            if(cartas[i] != init)
                changes++;
        }
    }
    return changes;
}

int main(){
    int n;
    string cartas;
    cin >> n;
    for(int i = 0; i < n; ++i){
        char aux;
        cin >> aux;
        if(aux == ' '){
            i--;
            continue;
        }else{
            cartas.push_back(aux);
        }
    }
    // cout << cartas;
    int first = solve('1', cartas);
    int second = solve('0', cartas);
    cout << min(first,second);
    return 0;
}