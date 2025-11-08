#include <bits/stdc++.h>

using namespace std;

void solve(vector<string>& words){

    map <string, vector <string>> grupos; 
    
    for(int i = 0; i < words.size(); ++i){
        string word = words[i];
        string og_word = words[i];

        sort(word.begin(), word.end());
        grupos[word].push_back(og_word);
    }

    vector <vector <string>> anagrams;
    for(auto it: grupos){
        auto indices = it.second;
        anagrams.push_back(indices);
    }
    return anagrams;
    //print groups words
    for(auto it: anagrams){
        for(auto word: it){
            cout << word << " ";
        }
        cout << endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }

    solve(words);

    return 0;
}