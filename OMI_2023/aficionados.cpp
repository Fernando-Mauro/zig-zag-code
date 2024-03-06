// https://omegaup.com/arena/problem/omi-2023-aficionados
#include <bits/stdc++.h> 

using namespace std;

int start, last;

bool solve(map <int, vector <int>> &mapping){
    // int aux;
    // scanf("%d", &aux);
    // auto finded = mapping.find(aux);
    // if(finded != mapping.end()){
    //     finded->second.push_back(i);
    // }else{
    //     mapping.insert({aux, vector <int> (1,i)});
    // }

    for(auto el: mapping){
        const int team = el.first;
        const int firstFan = el.second[0];
        for(int i = 1; i < el.second.size(); ++i){
            int distanceTotal = (el.second[i] - firstFan) + 1;
            int elementsBetween = i + 1;
            if(elementsBetween > floor(distanceTotal / 2)){
                start = firstFan;
                last = el.second[i];
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n;
    scanf("%d", &n);

    map <int, vector <int>> mapping;
    bool unstable = false;

    int current, last = -1, beforeLast = -1, start, end;
    
    for(int i = 0; i < n; ++i){
        scanf("%d", current);
        if(current == last){
            start = i - 1;
            end = i;
            unstable = true;
            break;
        }else if(current == beforeLast){
            start = i - 2;
            end = i;
            unstable = true;
            break;
        }else{
            beforeLast = last;
            last = current;
        }     
    }

    if(unstable){
        printf("%d %d",start + 1,end + 1 );
    }else{
        printf("-1");
    }
    return 0;
}