#include <bits/stdc++.h> 

using namespace std;

vector <int> brands;

int minBrand = INT_MAX;
int maxBrand = -1;
int friends = 0;

bool canRepart(int brandSize){

    int friendsHappy = 0;
    for(int i = 0; i < brands.size(); ++i){
        friendsHappy += (brands[i] / brandSize);
        if(friendsHappy >= friends)
            return true;
    }
    return friendsHappy >= friends;
}


int solve(){
    int start = 1;
    int end = maxBrand;

    int middle = 0;
    
    while(start <= end){
        middle = (start + end) / 2;
        if(canRepart(middle)){
            start = middle + 1;
        }else{
            end = middle - 1;
        }
    }    
    if(canRepart(start - 1)){
        return start - 1;
    }
    return 0;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n >> friends;
    brands.resize(n);

    for(int i = 0; i < n; ++i){
        cin >> brands[i];
        minBrand = min(brands[i], minBrand);
        maxBrand = max(brands[i], maxBrand);
    }

    cout << solve();
    return 0;
}