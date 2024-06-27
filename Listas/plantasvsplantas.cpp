#include <bits/stdc++.h> 

using namespace std;

set <int> dead;

stack <int> plantStack;
queue <int> plantQueue;
int t = 0;

char flagStructure = 'S';

void stackMethod(bool &canEat){
    while(canEat && !plantStack.empty()){
        canEat = false;
        // Sacar de la pila y meter a la cola
        int current = plantStack.top();
        plantStack.pop();
        while(!plantStack.empty() && current < plantStack.top()){
            current = plantStack.top();
            plantStack.pop();
            canEat = true;
        }
        plantQueue.push(current);
    }
    flagStructure = 'Q';
}

void queueMethod(bool &canEat){
    while(canEat && !plantQueue.empty()){
        canEat = false;
        // Sacar de la pila y meter a la cola
        int current = plantQueue.front();
        
        plantQueue.pop();

        while(!plantQueue.empty() && current > plantQueue.front()){
            // current = plantQueue.front();
            plantQueue.pop();
            canEat = true;
        }
        plantQueue.push(current);
    }
    flagStructure = 'S';
}

int main(){
    int n, aux;
    cin >> n;
    
    while(n--){
        cin >> aux;
        plantStack.push(aux);
    }
    
    bool canEat = true;
    do{
        switch(flagStructure){
            case 'S': stackMethod(canEat); break;
            case 'Q': queueMethod(canEat); break;
        }
        t++;
    }while(canEat && (!plantStack.empty() || !plantQueue.empty()));

    cout << t << endl;
    return 0;
}