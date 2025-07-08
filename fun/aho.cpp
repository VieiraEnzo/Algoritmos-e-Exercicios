#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int k = 26;
vector<int> ans;

struct Vertex{

    int output = 0;
    vector<int> next;

    Vertex() : next(k, -1) {}

};
struct Aho{

    vector<Vertex> trr;
    
    Aho() : trr(1){}

    void add_string(string s){
        int pos = 0;
        for(int i = 0; i < s.size(); i++){
            if(trr[pos].next[s[i] - 'a'] == -1){
                trr[pos].next[s[i] - 'a'] = trr.size();
                trr.push_back(Vertex ());
            }
            pos = trr[pos].next[s[i] - 'a'];
        }
        trr[pos].output++;
    }

    //Retorna prx estado saindo do atual adicionando chr
    int go(char chr, int std){
        if(trr[std].next[chr] == -1){

        }else{
            return trr[std].next[chr];
        }
    }

    void walk(char c){

    }

};

void solve(){

    string t; cin >> t;
    int m; cin >> m;
    ans.resize(m);

    Aho aho;

    for(int i = 0; i < m; i++){
        string p; cin >> p;
        aho.add_string(p);
    }

    for(int i = 0; i < t.size(); i++){
        aho.walk(t[0]);
    }

}   

int main() {
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    int t; t = 1;
    while (t--)
    {
        solve();
    }
}

