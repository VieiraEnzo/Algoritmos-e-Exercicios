#include <bits/stdc++.h>
using namespace std;

int l, c;
vector<vector<char>> mat(41, vector<char> (41));
vector<vector<set<int>>> countMat(41, vector<set<int>> (41));


bool CanReach(int i, int j){
    if(i < 0 || j < 0) return false;
    if(i >= l || j >= c) return false;
    return true;
}

bool anagram(int i, int j, pair<int,int> &dir, map<char,int> &word, int wordsize){
    int dirx = dir.first;
    int diry = dir.second;

    map<char,int> test;
    for(int t = 0; t < wordsize; t++){
        if(!CanReach(i, j)) return false;
        test[mat[i][j]]++;
        i += dirx;
        j += diry;
    }
    
    if(word.size() != test.size()) return false;
    for(auto &w : word){
        if(test[w.first] != w.second) return false;
    }
    return true;
}

void escreva(int i, int j, pair<int,int> &dir, int size, int w){
    int dirx = dir.first;
    int diry = dir.second;

    for(int t = 0; t < size; t++){
        countMat[i][j].insert(w);
        i += dirx;
        j += diry;
    }
}


int main(){
    cin.tie(0), ios_base::sync_with_stdio(0);
    cin >> l >> c;

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cin >> mat[i][j];
        }
    }

    vector<pair<int,int>> direction = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    int n; cin >> n;
    vector<map<char, int>> words(n);
    vector<int> wordsize(n);
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < s.size(); j++){
            words[i][s[j]]++;
        }
        wordsize[i] = s.size();
    }


    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            for(auto &dir : direction){
                for(int w = 0; w < words.size(); w++){
                    if(anagram(i, j, dir, words[w], wordsize[w])){
                        escreva(i, j, dir, wordsize[w], w);
                    }
                }
            }
        }
    }


    int ans = 0;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(countMat[i][j].size() > 1){
                ans++;
            }
        }
    }


    cout << ans << "\n";


}