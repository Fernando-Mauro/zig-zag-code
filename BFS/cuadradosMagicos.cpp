#include <bits/stdc++.h>

using namespace std;

struct State{
    array <short,8> numbers = {0};
    int movements;
};

State goal;

State start = {
    {1,2,3,4,8,7,6,5},
    0
};

// map <array <short, 8>, array <short,8>::iterator> visited;
set <array <short, 8>> visited;

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
}

State C(State current){
    short temp;

    temp = current.numbers[2];

    current.numbers[2] = current.numbers[1];
    current.numbers[1] = current.numbers[5];

    current.numbers[5] = current.numbers[6];
    current.numbers[6] = temp;  
}

State visitNeighbord(short opt, State current){
    switch(opt){
        case 1: return A(current);
        case 2: return B(current);
        case 3: return C(current);
    }
}

int solve(){

    queue <State> bfs;

    bfs.push(start);
    while(!bfs.empty()){
        State current = bfs.front();
        bfs.pop();
        visited.insert(current.numbers);

        if(isGoal(current))
            return current.movements;

        for(short i = 1; i <= 3; ++i){
            State neighbord = visitNeighbord(i, current);
            neighbord.movements++;
            if(visited.find(neighbord.numbers) == visited.end()){
                bfs.push(neighbord);
            }
        }

        // State newA = A(current);
        // State newB = B(current);
        // State newC = C(current);

        // bfs.push(newA);
        // bfs.push(newB);
        // bfs.push(newC);
    
    }
}

int main(){


    for(int i = 0; i < 4; ++i){
        cin >> goal.numbers[i];
    }

    for(int i = 7; i >= 4; --i){
        cin >> goal.numbers[i];
    }
    cout << solve();
    return 0;
}