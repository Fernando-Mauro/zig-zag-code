// https://omegaup.com/course/OMIexamenes/assignment/omi2002d1#problems/jeroglificos
#include <bits/stdc++.h>

using namespace std;

int coordX = 0;
int coordY = 0;
int orientation = 90;

bool isEqual(vector <vector <char>> &current, vector <vector <char>> &jeroglifico){
    for(int i = 0; i < current.size(); ++i){
        for(int j = 0; j < current[i].size(); ++j){
            if(current[i][j] != jeroglifico[i][j])
                return false;
        }
    }

    return true;
}

int lastDigit = -1;
void add(int x){

    if(lastDigit == -1){
        lastDigit = x;
        return;
    }

    int t = (lastDigit * 10) + x;

    switch(orientation){
        case 0: coordX += t; break;
        case 90:  coordY += t; break;
        case 180: coordX -= t; break;
        case 270: coordY -= t; break;
    }
}

void rotate(char d){

    switch(d){
        case 'A': break;
        case 'D' : {
            orientation -= 90;
            if(orientation < 0)
                orientation = 270;
        }; break;
        case 'I': {
            orientation += 90;
            if(orientation > 270)
                orientation = 0;            
        }
    }
}

int main(){
    map <int, vector <vector <char>>> digitos;

    for(int i = 0; i <= 9; ++i){
        vector <vector <char>> digito(5, vector <char> (5));

        for(int x = 0; x < 5; ++x){
            for(int j = 0; j < 5; ++j){
                cin >> digito[x][j];
            }
        }  
        digitos.insert({i, digito});
    }

    map <char, vector <vector <char>>> arrows;
    vector <char> abrv = {'A', 'D', 'I', 'F'};
    
    for(int i = 0; i < 4; ++i){
        vector <vector <char>> arrow(5, vector <char> (5));

        for(int x = 0; x < 5; ++x){
            for(int j = 0; j < 5; ++j){
                cin >> arrow[x][j];
            }
        }  
        arrows.insert({i, arrow});
    }


    vector <string> jeroglifico (5);

    for(int i = 0; i < 5; ++i){
        cin >> jeroglifico[i];
    }

    int size = jeroglifico[0].size();
    int iterations = size / 5;

    for(int i = 1; i <= iterations; ++i){
        vector <vector <char>> current(5, vector <char> (5));
        
        for(int x = 0; x < 5; ++x){
            for(int j = 0; j < 5; ++j){
                current[x][j] = jeroglifico[x][(j + 1 * i) - 1];
            }
        }

        for(int y = 0; y < 10; ++y){
            if(isEqual(current, digitos[y])){
                add(y);
            }
        }

        for(int y = 0; y < 4; ++y){
            if(isEqual(current, arrows[y])){
                rotate(abrv[y]);
            }
        }
    }

    cout << coordX << " " << coordY << "\n";

    // for(int i = 0; i < 10; ++i){
    //     cout << "--------------------------------------------------\n";
    //     for(int x = 0; x< 5; x++ ){
    //         for(int j = 0; j < 5; ++j){
    //             cout << digitos[i][x][j];
    //         }
    //         cout << "\n";
    //     }
    // }
    // for(int i = 0; i < 4; ++i){
    //     cout << "--------------------------------------------------\n";
    //     for(int x = 0; x < 5; x++ ){
    //         for(int j = 0; j < 5; ++j){
    //             cout << arrows[i][x][j];
    //         }
    //         cout << "\n";
    //     }
    // }

    return 0;
}