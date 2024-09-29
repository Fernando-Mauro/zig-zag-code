#include <bits/stdc++.h>

using namespace std;

bool isCyclic(map <int, vector <int>> adj, int start){
    set <int> visited;
    unordered_set <int> currentPath;

    stack <int> dfs;

    dfs.push(start);

    while(!dfs.empty()){
        int current = dfs.top();
        dfs.pop();

        // Check if is in the current path
        if(currentPath.find(current) != currentPath.end())
            return true;

        if(visited.find(current) != visited.end())
            continue;
        
        visited.insert(current);
        currentPath.insert(current);

        for(int neighbord: adj[current]){
            dfs.push(neighbord);
        }

        currentPath.erase(current);
    }
    return true;

}

void solve(map <int, vector <int>> &adjacencyList, int root){
    cout << ((isCyclic(adjacencyList, root)) ? "Hay un ciclo" : "No hay ciclo");
    
}

int main(){
    int n, m;
    int root;
    cin >> n >> m >> root;

    map <int, vector <int>> adjacencyList; 

    while(m--){
        int a, b;
        cin >> a >> b;

        adjacencyList[a].push_back(b);
    }

    solve(adjacencyList, root);

    return 0;
}