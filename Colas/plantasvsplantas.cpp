#include <bits/stdc++.h> 

using namespace std;

typedef long long int i64;
 
i64 t = 0;

struct Food{
    i64 size;
    i64 time;
};

void solve(vector <i64> &plants){
    
    stack <Food> stackPlants;
    for(int i = (plants.size() - 1); i >= 0; --i){
        Food newPlant = {
            plants[i],
            0
        };

        while(!stackPlants.empty() && stackPlants.top().size < newPlant.size){
            Food current = stackPlants.top();
            stackPlants.pop();
            if(current.time == newPlant.time)
                newPlant.time++;
            else
                newPlant.time = max(current.time, newPlant.time);
            t = max(t, newPlant.time);
        }
        stackPlants.push(newPlant);
    }
}

int main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int n;
    
    cin >> n;

    vector <i64> plants(n);
    for(int i = 0; i < n; ++i){

        cin >> plants[i];
    }

    solve(plants);
    cout << t << endl;

    return 0;
}