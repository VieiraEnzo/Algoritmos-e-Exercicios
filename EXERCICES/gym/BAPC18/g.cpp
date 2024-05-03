#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<int> v(3);
vector<char> oi = {'A', 'B', 'C'};

int solve(int l, int r){
    string comp;
    for(int i = 0; i < v[oi[0]- 'A']; i++)comp.push_back(oi[0]);
    for(int i = 0; i < v[oi[1]- 'A']; i++)comp.push_back(oi[1]);
    for(int i = 0; i < v[oi[2]- 'A']; i++)comp.push_back(oi[2]);

    int ans = 0;
    for(int i = l; i < r; i++){
        if(comp[i - l] != s[i]){
            ans++;
        }
    }
    return ans;
}


int main(){
    cin >> n;
    cin >> s;
    s.append(s);

    for(int i = 0; i < n; i++) v[s[i] - 'A']++;

    int ans = 1e9;
    for(int i = 0; i < n; i++){
        // for(int j = i; j < i+n; j++){cout << s[j];}
        // cout << endl;
        sort(oi.begin(), oi.end());
        do{
            ans = min(solve(i, i+n), ans);
            
        }while (next_permutation(oi.begin(), oi.end()));
    }
    
    cout << ans << endl;
}