#include <bits/stdc++.h>

using namespace std; 
bool comportation = true;
deque <int> numbersData;

void agrega(){
  int opt;
  cin >> opt;
  numbersData.push_back(opt);
}
void quita(){
  if(comportation){
    cout << numbersData.front() << "\n";
    numbersData.pop_front();
  }else{
    cout << numbersData.back() << "\n";
    numbersData.pop_back();
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  string option;
  while (cin>>option) {
    if(option == "AGREGA"){
      agrega();
    }else if(option == "QUITA"){
      quita();
    }else{
      comportation = !comportation;
    }
  }

  return 0;
}