#include <bits/stdc++.h> 

using namespace std;

set <int> dead;

struct plant{
    int size;
    int neighboord;

    bool operator<(const plant otherPlant)const{
        if(this->size == otherPlant.size)
            return true;
        else
            return this->size > otherPlant.size;
    }
};

priority_queue <plant> plants;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int current, last = -1;
    while(n--){
        cin >> current;

        if(last != -1){
            plants.push({last, current});
        }
        last = current;
    }
    plants.push({current, -1});
    
    while(!plants.empty()){
        cout << plants.top().size << " " << plants.top().neighboord << endl;
        plants.pop();
    }
    
    return 0;
}