#include <bits/stdc++.h>

using namespace std;

int minInsert = INT_MAX;

void solve(vector <char> &palyndrome, int index){

    int left = index - 1;
    int right = index + 1;

    int changes = 0;
    while(left >= 0 || right < palyndrome.size()){        
        
        if(left < 0 || right >= palyndrome.size()){
            changes++;
            right++;
            left--;
            continue;
        }

        if(palyndrome[left] != palyndrome[right]){
            int disRight = abs(right - int(palyndrome.size()));
            int disLeft = abs(left - 0);
            if(disRight < disLeft){
                left--;
                changes ++;
            }else if(disLeft < disRight){
                right++;
                changes++;
            }else{
                changes += 2;
                right++;
                left--;
            }
            
        }else{
            right++;
            left--;
        }
        

    }

    minInsert = min(minInsert, changes);
}

int main(){
    int n;
    cin >> n;

    vector <char> palyndrom(n);
    
    for(int i = 0; i <  n; ++i){
        cin >> palyndrom[i];
    }

    for(int i = 0; i < n; ++i){
        solve(palyndrom, i);
    }

    cout << minInsert;
    
    return 0;
}