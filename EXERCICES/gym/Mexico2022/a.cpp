#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3")
#pragma GCC optimize("O3","unroll-loops")
#pragma GCC optimize("O3","fast-math")

const int maxn = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

struct Matriz{

    int D = 2;
    int MOD = 1e9 + 7;
    vector<vector<int>> mat;

    Matriz(int D): D(D), mat(D, vector<int> (D)) {}
    
    vector<int>& operator[](int i){
        return mat[i];
    }
    Matriz operator*(Matriz& oth){
        Matriz res(D);
        for(int i = 0; i < D; i++){
            for(int j = 0; j < D;j ++){
                res[i][j] = 0;
                for(int k = 0; k < D; k++)
                    res[i][j] = (res[i][j] + (mat[i][k] *1ll *oth[k][j])%MOD)%MOD; 
            }
        }
        return res;
    }

    Matriz exp(long long e){
        Matriz res(D);
        for(int i = 0; i < D; i++)
            for(int j= 0; j < D; j++)
                res[i][j] = (i == j);
        
        Matriz base = *this;
        while (e > 0)
        {
            if(e & 1ll)
                res= res* base;
            base = base*base;
            e = e>>1;
        }
        return res;
    }
};


int fib(int n){
    if(n == 0) return 1;
    else if(n == 1) return 1;
    else if(n == 2 )return 1;

    Matriz resp(2);
    resp[0][0] = 1; resp[0][1] = 1; resp[1][0] = 1; resp[1][1] = 0;
    
    Matriz oi = resp.exp(n-2);

    // for(int i = 0; i < 2; i++){
    //     for(int j = 0; j < 2; j++)
    //         cout << oi[i][j] << " ";
    //     cout << endl;
    // }    
    return (oi[0][0] + oi[0][1]) % mod;
}


signed main(){
    cin.tie(0), ios_base::sync_with_stdio(0);

    vector<int> fibc(1e6 + 10);
    fibc[0]=  1;
    fibc[1]=  1;
    fibc[2]=  1;

    for(int i = 3; i <= 1e6; i++){
        fibc[i] = (fibc[i-1] + fibc[i-2])%mod; 
    }

    int n, m;
    cin >> n >> m;

    int ans = 1;
    vector <int> arr(m+2);
    arr[0] = -1, arr[m+1] = n+1;
    for(int i = 1; i <= m; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    //fib[1] = 1, fib[2] = 1, fib[3] = 2
    for(int i = 1; i < arr.size(); i++){
        int dist = arr[i] - arr[i-1] - 1;
        if(dist == 0){
            ans = 0;
            break;
        }
        if(dist < 1e6) ans = (ans * fibc[dist]) % mod; 
        else ans = (ans * fib(dist)) % mod;
    }

    cout << ans << "\n";

    return 0;
}