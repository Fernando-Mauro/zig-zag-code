#include <bits/stdc++.h> 

using namespace std;

set <int> dead;

int main(){
    int n;
    cin >> n;

    map <int, int> plants;
    
    int before, current;
    cin >> before;
    n--;
    while(n--){
        cin >> current;
        plants[before] = current;
        before = current;
    }
    plants[current] = -1;
    bool canErase = true;
    
    int time = 0;
        while(canErase){
            canErase = false;
            for(auto &plant:plants){
                if(dead.find(plant.first) == dead.end()){
                    if(plant.first > plant.second && plant.second != -1){
                        dead.insert(plant.second);
                        int currentNeighbord = plants[plant.second];
                        while(dead.find(currentNeighbord) != dead.end()){
                            currentNeighbord = plants[currentNeighbord];
                        }
                        plant.second = currentNeighbord;
                        canErase = true;
                    }
                }
            }
            time++;
        }
        cout << time - 1<< endl;
        return 0;
    }