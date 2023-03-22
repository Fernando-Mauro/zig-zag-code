#include <bits/stdc++.h>

using namespace std;

int min = INT_MIN;
int max = INT_MAX;
int solve(int &objective, vector <int> &numbers, int suma, int indice){
    if(suma == objective){
        return suma;
    }
    if(indice > (numbers.size() - 1)){
        return 0;
    }
    return min(abs(objetivo - solve()))
}
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int objective;
    while(cin >> objective){
        int n;
        cin >> n;
        vector <int> numbers(n);
        for(auto &it : numbers){
            cin >> it;  
        }
        cout << solve(objective, numbers,0, 0);
    }
    return 0;
}