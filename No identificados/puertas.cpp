#include <bits/stdc++.h> 

using namespace std;

int doors;
int redDoor;
vector <int> sequence;

int solve(){
    
    int current = redDoor;
    // Starts in the end 🐐
    for(int i = sequence.size(); i >= 0; ++i){
        int howManyErase = doors 
    }

}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> doors;
    cin >> redDoor;
    sequence.resize(doors -1);

    for(int i = 0; i < sequence.size(); ++i){
        cin >> sequence[i];
    }

    cout << solve();
    return 0;
}