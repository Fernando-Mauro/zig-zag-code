#include <bits/stdc++.h> 

using namespace std;


// int solve(char init, string &cartas){
//     int changes = 0;
//     for(int i = 0; i < cartas.length(); i++){
//         if(i % 2 == 0){
//             if(cartas[i] == init)
//                 changes++;
//         }else{
//             if(cartas[i] != init)
//                 changes++;
//         }
//     }
//     return changes;
// }


int checkChanges(string updated, string original){
    int changes = 0;

    for(int i = 0; i < original.size(); ++i){
        if(updated[i] != original[i])
            changes++;
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
            cartas += (aux);
        }
    }
    
    string firstString = "";
    for(int i = 0; i < cartas.size(); ++i){
        if(i % 2 == 0){
            firstString += "0";
        }else{
            firstString += "1";
        }
    }

    string secondString = "";
    for(int i = 0; i < cartas.size(); ++i){
        if(i % 2 == 0){
            secondString += "1";
        }else{
            secondString += "0";
        }
    }


    cout << min(checkChanges(firstString, cartas),checkChanges(secondString, cartas));
    return 0;
}