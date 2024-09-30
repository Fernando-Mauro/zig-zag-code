#include <bits/stdc++.h>

using namespace std;

// Chilly Willy solo piensa en palabras que conoce (no puede inventar palabras diferentes a las 
//  iniciales) e inicia pensando en la primer palabra del rap.

// Si Chilly Willy está pensando en una palabra de longitud 
//  puede pensar en otra palabra de la misma longitud solamente si la nueva palabra difiere con la anterior por una sola letra. Por ejemplo, si Chilly Willy esta pensando en la palabra "hielo" puede cambiar a la palabra "huelo" pero no puede cambiar a la palabra "huevo".

// Chilly Willy puede cambiar una palabra de longitud 
//  por una palabra de longitud menor si la nueva palabra es un prefijo o un sufijo de la palabra anterior. Como ejemplo, nuestro amigo puede pensar en la palabra "automovil" y después pensar en la palabra "auto".

// De manera similar, se puede cambiar una palabra de longitud 
//  por una diferente de longitud mayor si la palabra anterior es un prefijo o sufijo de la nueva palabra. Por ejemplo, Chilly Willy puede pensar primero en la palabra "pluma" y cambiar a la palabra "plumaje".

// Cualquiera de estos cambios de palabra requiere exactamente 
//  segundos para que Chilly Willy los realice.
struct Node{
    string word;
    float time;
};

map <string, vector <string>> adj;

int isPossible(string &first, string &second){
    if(first.size() == second.size()){
        int changes = 0;
        for(int i = 0; i < first.size(); ++i){
            if(first[i] != second[i])
                changes++;
        }

        if(changes == 1)
            return 1;
    }else if(first.size() > second.size()){
        auto isFound = first.find(second);
        if(isFound != string::npos)
            return 1;
    }else if(first.size() < second.size()){
        auto isFound = second.find(first);
        if(isFound != string::npos)
            return 1;        
    }

    return false;
}

void makeGraph(vector <string> &words){

    for(int i = 0; i < words.size(); ++i){

        for(int j = 0; j < words.size(); ++j){
            if(i == j) continue;
            
            bool isWay = isPossible(words[i], words[j]);

            if(isWay){
                adj[words[i]].push_back(words[j]);
            }
        }
    }
    
    
}

float bfs(string &start, string &end){
    queue <Node> bfsQueue;
    unordered_set <string> visited;

    bfsQueue.push({start, 0});

    while(!bfsQueue.empty()){
        Node current = bfsQueue.front();
        bfsQueue.pop();
        
        visited.insert(current.word);
        if(current.word == end)
            return current.time;

        for(int i = 0; i < adj[current.word].size(); ++i){
            if(visited.find(adj[current.word][i]) == visited.end()){
                Node neighbord = {
                    adj[current.word][i],
                    current.time + 0.2
                }; 

                bfsQueue.push(neighbord);
            }
        }

    }

}
int main(){

    int n, r;

    cin >> n >> r;

    vector <string> words(n);

    for(int i = 0; i < n; ++i){
        cin >> words[i];
    }   

    makeGraph(words);

    vector <int> goal(r);
    
    float time = 0;
    cin >> goal[0];
    for(int i = 1; i < r; ++i){
        cin >> goal[i];
        string start = words[goal[i - 1] - 1];
        string end = words[goal[i] - 1];
        
        time += bfs(start, end);
    }

    cout << fixed << setprecision(1) << time;
    // for(auto it:adj){
    //     cout << "\n" <<  it.first << "\n";
    //     for(int i = 0; i < it.second.size(); ++i){
    //         cout << it.second[i] << " ";
    //     }
    // }
    return 0;
}