#include <bits/stdc++.h>

using namespace std;

bool isOrdered(int start, vector <int> &numbers){
    
    for(int i = start + 1; i < numbers.size(); ++i){
        if(numbers[i] < numbers[i - 1])
            return false;
    }
    return true;
}

int solve(vector <int> &numbers){
    int start = 0;
    int end = numbers.size() - 1;
    int middle = start + (end - start)  / 2;

    while(start < end){
        if(isOrdered(start, numbers)){
            return abs(start - int(numbers.size()));
        }else{
            start = middle + 1;
            middle = start + (end - start) / 2;
        }
    }
    return 1;
}
int main(){
    int n;
    cin >> n;
    vector <int> numbers(n);

    for(int i = 0; i < n; ++i){
        cin >> numbers[i];
    }

    cout << solve(numbers);
    return 0;
}