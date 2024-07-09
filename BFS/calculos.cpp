#include <bits/stdc++.h> 

using namespace std;

int a, b, n;

unordered_set <int> visited;

struct Node{
    int number;
    int steps;
};

int solve(){
    queue <Node> bfs;

    Node root = {1, 0};
    bfs.push(root);
    visited.insert(1);

    while(!bfs.empty()){
        Node current = bfs.front();

        bfs.pop();
        Node firstNext = {current.number * a, current.steps + 1};
        Node secondNext = {current.number / b, current.steps + 1};
        
        if(firstNext.number > 9999)
            firstNext.number = 1;

        if(secondNext.number > 9999)
            secondNext.number = 1;
        if(visited.find(firstNext.number) == visited.end()){
            bfs.push(firstNext);
            visited.insert(firstNext.number);
        }
        if(visited.find(secondNext.number) == visited.end()){
            bfs.push(secondNext);
            visited.insert(secondNext.number);
        }


        if(firstNext.number == n){
            return firstNext.steps;
        }

        if(secondNext.number == n){
            return secondNext.steps;
        }

    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> a >> b >> n;

    cout << solve() << endl;
    return 0;
}