#include <bits/stdc++.h> 

using namespace std;

deque <int> students;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);


    int n, temp;
    cin >> n;
    while(n--){
        cin >> temp;
        students.push_back(temp);
    }

    int querys;
    char letter;
    cin >> querys;

    while(querys--){
        cin >> letter;
        switch (letter){
            case 'M' : move(); break;
            case 'L' : laurencio(); break;
            case 'Q' : remove(); break;
        }
    }
    return 0;
}