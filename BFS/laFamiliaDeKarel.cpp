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

void solve(adjacency_list &family){
    queue <Familiar> bfs;
    
    Familiar nodeRoot = {root, root, 1};

    bfs.push(nodeRoot);
    
    while(!bfs.empty()){
        Familiar current = bfs.front();
        bfs.pop();

        if(current.father == karelFather)
            karelGeneration = current.generation;

        // Visit neighbords
        for(i64 i = 0; i < family[current.number].size(); ++i){
            // Avoid loops in the father
            if(family[current.number][i] == current.father)
                continue;

        
            sums[current.generation + 1]++;


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

    adjacency_list family(n + 1, vector <i64> (0));
    sums.resize(n + 1);
    // index in 1
    for(i64 i = 1; i <= n; ++i){
        i64 father;
        cin >> father;
        family[father].push_back(i);
        
        if(i == father){
            root = i;
        }

    }

    solve(family);

    cout << sums[karelGeneration];
    
    return 0;
}