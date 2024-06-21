#include <bits/stdc++.h> 

using namespace std;

struct Bot{
    int min;
    int max;
};

struct Capsule{
    int oxygen;
    int capacity;

    bool operator<(const Capsule &a){
        return this->oxygen < a.oxygen;
    }
    bool operator<(const int &a){
        return this->oxygen < a;
    }
};

int maxBots = 0;

void solve(vector <Bot> &nanoBots, vector <Capsule> &capsules){
    
    for(int i = 0; i < nanoBots.size();){
        auto search = lower_bound(capsules.begin(), capsules.end(), nanoBots[i].min);
        if(search != capsules.end() && search->capacity > 0 && nanoBots[i].min <= nanoBots[i].max && search->oxygen >= nanoBots[i].min && search->oxygen <= nanoBots[i].max){
            maxBots++;
            search->capacity--;
            search->oxygen -= nanoBots[i].min;
            i++;
        }else if(nanoBots[i].min > nanoBots[i].max){
            i++;
        }else{
            nanoBots[i].min++;
        }
    }

}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <Bot> nanoBots(n);

    for(int i = 0; i < n; ++i){
        cin >> nanoBots[i].min;        
        cin >> nanoBots[i].max;        
    }
    int k;
    cin >> k;
    vector <Capsule> capsules(k);
    

    for(int i = 0; i < k; ++i){
        cin >> capsules[i].oxygen;        
        cin >> capsules[i].capacity;        
    }   

    sort(capsules.begin(), capsules.end());
    
    solve(nanoBots, capsules);


    cout <<  maxBots<< endl;
    return 0;
}