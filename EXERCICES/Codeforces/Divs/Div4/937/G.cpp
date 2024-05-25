#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
pair<int,int> dp[16][(1<<16)];

void solve(){
    map<string, int> mp;
    int e = 0; cin >> n;
    vector<pair<int,int>> items(n);
    for(int i = 0; i < n; i++){
        string a, b; cin >> a >> b;
        if(mp.count(a) == 0){
            mp[a] = e++;
        }
        if(mp.count(b) == 0){
            mp[b] = e++;
        }
        items[i] = {mp[a], mp[b]};
    }

    int dp[n][1<<n];
    //dp[i][j] = max(acabando em i, com a mask j)

    for(int i = 0; i < n; i++){                 
        for(int j = 0; j < (1<<n); j++){
            if(!(j & (1<<i))) continue;     //Para cada mask, verifica se acaba em i
            for(int k = 0; k < n; k++){     //Pegando o item k, em cima dessa mask
                if(!(j & (1<<k))) continue;
                if(items[i].first == items[k].first || items[i].second == items[k].second){
                    dp[i][j] = max(dp[i][j], dp[k][j]);
                }
            }
        }
    }

}


int main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}