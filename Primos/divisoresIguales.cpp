#include <bits/stdc++.h> 

using namespace std;

const int MAX = 2000000;


short dividerNumbers[MAX];


int main(){    
    int n;
    cin >> n;

    for(int i = 1; i < MAX; ++i){
        for(int j = i; j < MAX; j += i){
            ++dividerNumbers[j];
        }
    }

    int left = n - 1;
    int right = n + 1;
    while(true){
        if(right < MAX && dividerNumbers[n] == dividerNumbers[right]){
            cout << right << "\n";
            break;
        }
        if(left > 0 && dividerNumbers[n] == dividerNumbers[left]){
            cout << left << "\n";
            break;
        }

        --left;
        ++right;
    }


    return 0;
}