// 
#include <bits/stdc++.h> 

using namespace std;

typedef long long int i64;
typedef vector <vector <i64>> adjacency_list;

vector <i64> sums;

i64 root = -1;
i64 karelFather;
i64 familyCount = 0;
i64 karelGeneration = -1;

struct Familiar{
    i64 number;
    i64 father;
    i64 generation;
};

void solve(unordered_map <int, vector <int>> &family){
    queue <Familiar> bfs;
    
    Familiar nodeRoot = {root, root, 1};

    bfs.push(nodeRoot);
    
    while(!bfs.empty()){
        Familiar current = bfs.front();
        bfs.pop();

        if(current.father == karelFather)
            karelGeneration = current.generation;

        sums[current.generation]++;
        
        // Visit neighbords
        for(i64 i = 0; i < family[current.number].size(); ++i){
            
            if(family[current.number][i] == current.father)
                continue;    

            Familiar neighbord = {family[current.number][i], current.number, current.generation + 1};
            bfs.push(neighbord);
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    i64 n;
    cin >> n;
    cin >> karelFather;

    unordered_map <int, vector <int>> family;

    sums.resize(n * 2,0);
    
    // index in 1
    for(i64 i = 1; i <= n; ++i){
        i64 father;
        cin >> father;   
        if(i == father){
            root = i;
        }else{

        family[father].push_back(i);
        }
    }

    solve(family);

    cout << sums[karelGeneration];
    
    return 0;
}