#include <bits/stdc++.h> 

using namespace std;

typedef long long int i64;

deque <i64> students;

void move(){
    int back;
    cin >> back;

    if(students.empty())
        return;
    
    if(back == 1){
        i64 front = students.front();
        students.pop_front();
        students.push_back(front);
    }else{
        i64 back = students.back();
        students.pop_back();
        students.push_front(back);
    }
}

void laurencio(){
    int student;
    cin >> student;

    auto position = binary_search(students.begin(), students.end(), student);
     
}
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
            case 'M': move(); break;
            case 'L' : laurencio(); break;
            case 'Q' : remove(); break;
        }
    }
    return 0;
}