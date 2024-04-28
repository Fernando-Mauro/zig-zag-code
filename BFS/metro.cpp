// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://omegaup.com/arena/problem/OMI2018-Metro
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;
vector<bool> hasCycle;
vector<vector<int>> doorsGraph;

// Run a dfs to traverse the graph looking for cycles, additionally we keep track of childs cycles to also mark the nodes
// that are not part of the cycle but can lead to a cycle, so when we detect the cycle we backtrack and check.
// Return the number of childs that doesn't have a cycle.
int dfs(int node) {
    // Base condition, if we are on a leaf node. Node has no neighboors.
    if (doorsGraph[node].size() == 0) {
        // Node is fine, doesn't have any cycle as we are in the end. 
        hasCycle[node] = false;
        return 1;
    }

    // If we already visited this node, we return 1 if that node is not in a cycle or 0 if it is.
    if (visited[node]) {
        if (hasCycle[node]) {
            return 0;
        } else {
            return 1;
        }
    }
    
    // Mark as visited
    visited[node] = true;

    // Visit the childs of our node and count how many of them have no cycles.
    int childWithNoCycles = 0;
    for (int i=0; i<doorsGraph[node].size(); i++) {
        childWithNoCycles += dfs(doorsGraph[node][i]);
    }

    // We should have the same number of childs and the same number of childs not having a cycle to consider this node also outside of a cycle.
    if (childWithNoCycles == doorsGraph[node].size()) {
        hasCycle[node] = false;
        return 1;
    }

    // If we are here, it means that we have a cycle on this node and we need to mark it and return 0. 
    hasCycle[node] = true;
    return 0;
}

bool canWeCloseAllDoors(vector<int> &initialOpenedDoors) {
    bool isPossible = true;
    for (int i=0; i<initialOpenedDoors.size(); i++) {
        int door = initialOpenedDoors[i];

        if (hasCycle[door]) {
            isPossible = false;
            break;
        }
    }

    return isPossible;
}

// NOTE: DOORS ARE 1-index.
int main() {
    int doors, notWorkingDoors, questions;
    cin>>doors>>notWorkingDoors>>questions;

    visited.resize(doors + 1, false);
    hasCycle.resize(doors + 1, true);
    doorsGraph.resize(doors + 1, vector<int>());

    // Read which doors are going to be opened when notWorkingDoor is closed.
    for (int i=0; i<notWorkingDoors; i++) {
        int doorIndex; 
        cin>>doorIndex;

        int numbersOfDoorsWillOpen;
        cin>>numbersOfDoorsWillOpen;

        for (int k=0; k<numbersOfDoorsWillOpen; k++) {
            int ithDoor;
            cin>>ithDoor;
            doorsGraph[doorIndex].push_back(ithDoor);
        }
    }

    // Pre-Process the answer: We look for cycles on nodes.
    for (int i=1; i<=doors; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Read the questions:
    for (int i=0; i<questions; i++) {
        vector<int> initialOpenedDoors = {};
        int initialDoors;

        cin>>initialDoors;

        for (int k=0; k<initialDoors; k++) {
            int ithDoor;
            cin>>ithDoor;
            initialOpenedDoors.push_back(ithDoor);
        }

        // Process Question
        bool isPossible = canWeCloseAllDoors(initialOpenedDoors);

        // Print Answer per question
        if (isPossible) {
           cout<<"S"<<endl; 
        } else {
            cout<<"N"<<endl;
        }
    }

    return (0);
}