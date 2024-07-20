#include <bits/stdc++.h> 

using namespace std;

int moscas[60001] = {0};
int maxNum = -1;

void findMaxNum(){
    int currentFlys = 0;
    
    for(int i = 0; i < 60001; ++i){
        currentFlys += moscas[i];
        maxNum = max(currentFlys, maxNum);
    }
}

int main(){
    int n;
    cin >> n;

    while(n--){
        int start, end;
        cin >> start >> end;

        moscas[start]++;
        moscas[end]--;
    }

    findMaxNum();

    cout << maxNum << "\n";
    int currentFlys = 0;
    for(int i = 0; i < 60001; ++i){
        currentFlys += moscas[i];
        
        if(currentFlys == maxNum){
            cout << i << " ";
            i++;  
            while(moscas[i] == 0) i++;
            cout << i << "\n";
            
            i--;
        }

    }

    return 0;
}