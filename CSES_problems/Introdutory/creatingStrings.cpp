#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
string v;int n; string m;
vector<int> util(8);set<string> s;

void brincar(int k){
    for(int i=0; i < n; i ++){
        if(!util[i]){
            m[k] = v[i];
            util[i] = 1;
            if(k == n-1){
                s.insert(m);
            }
            else{
                brincar(k+1);   
            }
            util[i] = 0;
        }
        else{continue;}
    }
}



int main(){
    fastio;
    cin >> v;
    n = v.size();
    m.resize(n);
    brincar(0);
    cout << s.size() << endl;
    for(string a : s){
        cout << a << endl;
    }
}