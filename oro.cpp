#include <bits/stdc++.h>
using namespace std;

void search(vector<int> &rocks, int maxGold, int posicion, int actualGold, int &minimoactualGold) {
    
    if (currentGold >= maxGold) {
        minimoactualGold = min(minimoactualGold, actualGold);
    }
    
    for (int i = posicion+1; i < rocks.size(); ++i) {
        search(rocks, maxGold, i, actualGold + rocks[i], mininimoactualGold);
    }
}

int main() {
    
    int rockasTotal;
    vector<int> rocks;
    int maxOro;
    
    cin >> rockasTotal;
    cin >> maxOro;
    
    for (int i = 0; i < rockasTotal; ++i) {
        int aux;
        cin >> aux;
        rocks.push_back(aux);
    }
    
    
    int actualGold = INT_MAX;
    
    for (int i = 0; i< rockasTotal; ++i ) {
        search(rocks, maxOro, i, rocks[i], actualGold);
    }
    
    
    int reRocks = actualGold - maxOro;
    
    cout << reRocks <<"\n";
    
    return (0);
}