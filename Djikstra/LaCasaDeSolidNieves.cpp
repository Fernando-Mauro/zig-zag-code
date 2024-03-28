#include <bits/stdc++.h>


using namespace std;

struct Node {
    int to, weight;

    bool operator<(const Node & rhs)const{
        return rhs.weight < weight;
    }
};

vector <int> djikstra(vector <vector <Node>> &adjacencyList, int origin){
    set <int> spt; // visited nodes
    vector <int> distances(adjacencyList.size(), INT32_MAX); // by default all distances are INF 

    priority_queue <Node> nextNodes;
    // The distance to himself is 0
    distances[origin] = 0;
    nextNodes.push({origin, 0});

    while(!nextNodes.empty()){
        // Sacamos al siguiente nodo con menos peso
        Node current = nextNodes.top();
        nextNodes.pop();

        // Node already processed
        if(spt.find(current.to) != spt.end())
            continue;
        
        for(Node neighbord: adjacencyList[current.to]){
            int weight = neighbord.weight + current.weight;
            if(distances[neighbord.to] > weight){
                distances[neighbord.to] = weight;
                nextNodes.push({neighbord.to, weight});
            }
        }

        spt.insert(current.to);
    }

    return distances;
}

void solve(vector<vector <Node>> &adjacencyList, vector <int> &mostVisited, int nodes){
    // deploy djikstra in each node >:v?
    double minAverage = INT_MAX;
    int start = -1;
    int sum = 0;
    
    for(int i = 1; i <= nodes; ++i){
        auto distances = djikstra(adjacencyList, i);
        sum = 0;
        for(int j = 0; j < mostVisited.size(); ++j){
            sum += distances[mostVisited[j]]; 
        }
        double average = double(sum) / double(adjacencyList.size());
        if(average < minAverage){
            minAverage = min(average, minAverage);
            start = i;
        }

    }
    cout << start;
}
int main(){
    // p -> cities, f -> most visited, c -> the conections
    int p, f,c;
    scanf("%d%d%d", &p, &f, &c);

    // 501 with centinel 
    vector<std::vector<Node>> adjacencyList(p + 1, vector <Node> (0));
    vector <int> mostVisited(f);
    int trash;
    for(int i = 0; i < f; i++)
        scanf("%d", &mostVisited[i]); 

    while(c--){
        int start, end, weight;
        scanf("%d%d%d", &start, &end, &weight);
        adjacencyList[start].push_back(Node({end, weight}));
        adjacencyList[end].push_back(Node({start, weight}));        
    }
    
    solve(adjacencyList, mostVisited, p);
    // auto distances = djikstra(adjacencyList, 4);

    // for (int i = 0; i < distances.size(); ++i) {
    //     cout << "Desde " << 4 << " hasta " << i << ": " << distances[i] << "\n";
    // } 
}