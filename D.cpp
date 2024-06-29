#include <bits/stdc++.h>
using namespace std;


struct SegTree{
    int n;
    struct Node{
        int val;
        Node operator+(Node other) const{
            return {max(this-> val, other.val)};
        }
        Node operator=(int x){
            return {this->val = x};
        }
    };

    Node neutral = {-1000000000};
    vector<Node> t;

    void contruct(vector<int> a){
        n = a.size();
        t.resize(4*n);
        build(a,1,0,n-1);
    }

    void build(vector<int> &a, int v, int tl, int tr){
        if(tl == tr){
            t[v] = a[tl];
        }else{
            int tm = (tl+tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = t[2*v] + t[v*2+1];
        }
    }

    int query(int l, int r){
        // if(l < r) swap(l,r);
        return query(1,0,n-1,l,r).val; 
    }

    Node query(int v, int tl, int tr, int l, int r){
        if(l > r)
            return neutral;
        if(l == tl && r == tr){
            return t[v];
        }
        int tm = (tl+tr)/2;
        return query(v*2, tl, tm, l , min(r,tm)) + 
                query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    void update(int pos, int val){
        update(1, 0, n-1, pos, val);
    }

    void update(int v, int tl, int tr, int pos, int new_val){
        if(tl == tr){
            t[v] = new_val;
        } else{
            int tm = (tl+tr)/2;
            if(pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else 
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = t[2*v] + t[v*2+1];
        }
    }
};


int main(){

    cin.tie(0), ios_base::sync_with_stdio(0);

    int n; cin >> n;
    vector<pair<int,int>> pos(n*n+10);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            int temp; cin >> temp;
            pos[temp] = {i,j};
        }

    int dp[n*n+10][2][2];
    for(int i = 1; i <= n*n; i++) dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = 1;

    int vertical_cima[n+2][n+2][2]; 
    int vertical_baixo[n+2][n+2][2];
    int horizontal_esquerda[n+2][n+2][2];
    int horizontal_direita[n+2][n+2][2];
    for(int i = 0; i <= n+1; i++){
        for(int j = 1; j<= n; j++){
            vertical_cima[i][j][0] = vertical_cima[i][j][1] = 0;
            vertical_baixo[i][j][0] = vertical_baixo[i][j][1] = 0;
            horizontal_direita[i][j][0] = horizontal_direita[i][j][1] = 0;
            horizontal_esquerda[i][j][0] = horizontal_esquerda[i][j][1] = 0;
        }
    }

    for(int i = n*n; i >= 1; i--){
        int x = pos[i].second;
        int y = pos[i].first;

        //Vertical por cima
        dp[i][0][0] = max({vertical_cima[x][y+1][1], 
                          horizontal_esquerda[y][x-1][0] + 1,
                          horizontal_direita[y][x+1][1] + 1});
        
        //Vertical por baixo
        dp[i][0][1] = max({vertical_baixo[x][y-1][0],
                          horizontal_esquerda[y][x-1][0] + 1,
                          horizontal_direita[y][x+1][1] + 1 });

        //Horizontal pela esquerda
        dp[i][1][0] = max({horizontal_esquerda[y][x+1][1],
                          vertical_cima[x][y-1][0] + 1,
                          vertical_baixo[x][y+1][1] + 1 });

        //Horizontal pela direita
        dp[i][1][1] = max({horizontal_direita[y][x-1][0],
                          vertical_cima[x][y-1][0] + 1,
                          vertical_baixo[x][y+1][1] + 1 });

        vertical_cima[x][y].update(y, dp[i][0][0]);
        vertical_baixo[x].update(y, dp[i][0][1]);
        horizontal_direita[y].update(x, dp[i][1][0]);
        horizontal_esquerda[y].update(x, dp[i][1][1]);
    }

    // for(int i = 1; i <= n*n; i++){
    //     cout << dp[i][0][0] << " ";
    // }cout << "\n";
    // for(int i = 1; i <= n*n; i++){
    //     cout << dp[i][0][1] << " ";
    // }cout << "\n";
    // for(int i = 1; i <= n*n; i++){
    //     cout << dp[i][1][0] << " ";
    // }cout << "\n";
    // for(int i = 1; i <= n*n; i++){
    //     cout << dp[i][1][1] << " ";
    // }cout << "\n";

    int ans = 0;
    for(int i = 1; i <= n*n; i++){
        ans = max({ans, dp[i][0][0], dp[i][0][1], dp[i][1][0], dp[i][1][1]});
    }

    cout << ans << "\n";
}   