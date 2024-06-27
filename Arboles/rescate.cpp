#include <bits/stdc++.h> 

using namespace std;

typedef vector <vector <int>> matrix;

void postOrder(){
    
}

bool solve(int broken, int current){
    
    return false;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    matrix adjacencyMatrix(n);
    
    while(n--){
        int current, next;
        cin >> current >> next;
        adjacencyMatrix[current].push_back(next);
    }

    while(q--){
        int broken, current;
        cin >> broken >> current;
        cout << solve(broken, current);
    }
    return 0;
}