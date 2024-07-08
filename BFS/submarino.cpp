#include <bits/stdc++.h> 

using namespace std;

typedef vector <vector <bool>> matrix;


unordered_map <int, vector <int>> adjacencyList;
int exitNode = -1;

unordered_set <int> visited;
struct Node{
    int time;
    int number;
};

int solve(int time){
    int total = 0;
    queue <Node> bfs;

    Node root = {0, exitNode};
    bfs.push(root);
    visited.insert(exitNode);

    while(!bfs.empty()){
        Node current = bfs.front();
        bfs.pop();
        
        // Explore neighbords
        for(auto it: adjacencyList[current.number]){
            
            if(visited.find(it) == visited.end()){
                Node newNeighbord = {current.time + 1, it};
                if(newNeighbord.time < time)
                    total++;
                bfs.push(newNeighbord);
                visited.insert(it);
            }

        }
    }

    return total;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, e, time;
    cin >> n >> e >> time;
    exitNode = n;

    int first, second;
    while(e--){
        cin >> first >> second;
        adjacencyList[first].push_back(second);
        adjacencyList[second].push_back(first);
    }

    cout << solve(time) << "\n";
    return 0;
}