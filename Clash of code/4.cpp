#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    map <string, int> calcetines;
    while(n--){
        string type;
        int size;
        string color;
        cin >> type >> size >> color;
        if(type == "sock"){
            if(calcetines.find(color) != calcetines.end()){
                if(calcetines.find(color) -> second == size && calcetines.find(color) -> first == color){
                    calcetines.erase(color);
                }
            }else{
                calcetines.insert({color, size});
            }
        }
    }
    cout << calcetines.size() << endl;
    if(calcetines.size() > 0){
        for(auto itr = calcetines.begin(); itr != calcetines.end(); ++itr){
            cout << itr -> second << " " << itr -> first << endl;
        }
    }
    return 0;
}