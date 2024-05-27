#include <bits/stdc++.h>

#define int long long
using namespace std;

#ifdef local
    #include "/home/enzo/Documents/Prog/OBItraining/debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool can(int i, int j, int n, int m){
    if(i < 0) return false;
    if(i >= n) return false;
    if(j < 0) return false;
    if(j >= m) return false;
    return true;
}

bool equal(int k, int l){
    if(l == k) return true;
    if(l == 1 || k == 1) return true;
    return false;
}

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    int k, l; cin >> k >> l;

    char mat[n][m];
    k--;l--;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];

    bool first = true;
    int ans = 0;
    pair<int,int> pt = {0,0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;j++){
            if(mat[i][j] == '*') continue;
            if(first) {pt.first = i; pt.second = j; first = false;}
            int count = 0;
            if(k == 0 || l == 0){
                if(l > k) swap(l, k);
                if(can(i+k, j, n, m) && mat[i+k][j] == '*') count++;
                if(can(i-k, j, n, m) && mat[i-k][j] == '*') count++;
                if(can(i, j+k, n, m) && mat[i][j+k] == '*') count++;
                if(can(i, j-k, n, m) && mat[i][j-k] == '*') count++;
            }
            else{
                for(int t = 0; t < 2; t++){
                    if(can(i+l, j+k, n, m) && mat[i+l][j+k] == '*') count++;
                    if(can(i+l, j-k, n, m) && mat[i+l][j-k] == '*') count++;
                    if(can(i-l, j-k, n, m) && mat[i-l][j-k] == '*') count++;
                    if(can(i-l, j+k, n, m) && mat[i-l][j+k] == '*') count++;
                    swap(l,k);
                    if(k == l) break;
                }
            }
            if(count > ans){ans = count; pt.first = i; pt.second = j;}
            // cout << i << " " << j << " "  << count << "\n";
        }
    }

    cout << pt.first + 1  << " " << pt.second + 1 << "\n";

}