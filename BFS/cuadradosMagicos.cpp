// https://omegaup.com/arena/problem/Cuadrados-Magicos/#problems
#include <bits/stdc++.h>

using namespace std;

struct State{
    array <short,8> numbers = {0};
    int movements;
};

struct Node{
    short step;
    array <short,8> parent;
};

State goal;

State start = {
    {1,2,3,4,8,7,6,5},
    0
};


map <array <short, 8>, Node> visited;
// set <array <short, 8>> visited;

bool isGoal(State &current){

    for(int i = 0; i < 8; ++i){
        if(current.numbers[i] != goal.numbers[i])
            return false;
    }

    return true;
}

State A(State current){
    
    for(int i = 0; i < 4; ++i){
        swap(current.numbers[i], current.numbers[i + 4]);
    }

    return current;
}

State B(State current){
    for(int i = 3; i > 0; --i){
        swap(current.numbers[i], current.numbers[i - 1]);
    }

    for(int i = 7; i > 4; --i){
        swap(current.numbers[i], current.numbers[i - 1]);
    }
    return current;
}

State C(State current){
    short temp;

    temp = current.numbers[2];

    current.numbers[2] = current.numbers[1];
    current.numbers[1] = current.numbers[5];

    current.numbers[5] = current.numbers[6];
    current.numbers[6] = temp;
    return current;  
}

State visitNeighbord(short opt, State current){
    switch(opt){
        case 1: return A(current);
        case 2: return B(current);
        case 3: return C(current);
    }
}

void printPath(State &current){

    cout << current.movements << endl;
    auto parent = visited.find(current.numbers);

    queue <short> steps;

    while(parent->second.parent[0] != -1){
        steps.push(parent->second.step);
        parent = visited.find(parent->second.parent);
    }

    while(!steps.empty()){
        switch(steps.front()){
            case 1: cout << "A\n"; break;
            case 2: cout << "B\n"; break;
            case 3: cout << "C\n"; break;
        }
        steps.pop();
    }

}

void solve(){

    queue <State> bfs;

    bfs.push(start);

    Node startNode = {
        -1,
        {-1}
    };
    visited.insert({start.numbers, startNode});

    while(!bfs.empty()){
        State current = bfs.front();
        bfs.pop();

        if(isGoal(current)){
            printPath(current);
            return;
        }

        for(short i = 1; i <= 3; ++i){
            State neighbord = visitNeighbord(i, current);
            neighbord.movements++;
            if(visited.find(neighbord.numbers) == visited.end()){
                bfs.push(neighbord);
                
                visited.insert({neighbord.numbers,{i, current.numbers}});
            }
        }
    }
}

int main(){


    for(int i = 0; i < 4; ++i){
        cin >> goal.numbers[i];
    }

    for(int i = 7; i >= 4; --i){
        cin >> goal.numbers[i];
    }

    solve();
    return 0;
}