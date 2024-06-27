#include <bits/stdc++.h> 

using namespace std;

unordered_set <int> served;

int minStudent, maxStudent;

vector <int> students;
vector <int> desfase;

int binarySearch(int studentNumber){
    int start = 0;
    int end = students.size() - 1;
    int middle;
    
    while(start <= end){
        middle = start + (end - start) / 2;
        if(students[middle] == studentNumber)
            return middle;
        if(students[middle] > studentNumber){
            end = middle -1;
        }
        if(students[middle] < studentNumber){
            start = middle + 1;
        }
    }
    return -1;
}


void move(int pos){

    for(int i = 0; i < desfase.size();++i){
        desfase[i] -= (pos);
    }
}

string laurencio(int studentNumber){
    int pos = binarySearch(studentNumber);

    
    if(served.find(students[pos]) == served.end()){
        return to_string(((pos += desfase[pos]) % students.size()) + 1);
    }

    // No se encontró el estudiante, ya fue atendido
    return "No laurencio";
}

void fixedDesfase(int posDes){
    for(int i = 0; i < students.size(); ++i){
        if(posDes < ((i + desfase[i]) % students.size())){
            desfase[i]--;
        }
    }
}

void remove(int pos){
    int posDes = 0;
    
    if(pos == -1){
        served.insert(students[minStudent]);
        posDes = (minStudent + desfase[minStudent]) % students.size();
        minStudent++;
    }else{
        served.insert(students[maxStudent]);
        posDes = (maxStudent + desfase[maxStudent]) % students.size();
        maxStudent--;
    }

    fixedDesfase(posDes);
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    students.resize(n);
    desfase.resize(n, 0);
    

    minStudent = 0;
    maxStudent = n - 1;

    for(int i = 0; i < n; ++i){
        cin >> students[i];
    }

    int q;
    cin >> q;
    
    while(q--){
        char opt;
        cin >> opt;

        int pos;
        cin >> pos;
        switch (opt){
            case 'M': move(pos); break;
            case 'L': cout << laurencio(pos) << "\n"; break;
            case 'Q': remove(pos); break;
        }
    }

    return 0;
}