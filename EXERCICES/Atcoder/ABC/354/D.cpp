#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    fastio;
    int a, b, c, d; cin >> a >> b >> c >> d;
    int dfx = (c-a);
    int dfy = (d-b);

    vector<vector<int>> mat = {{1, 2 ,1, 0}, 
                               {2, 1, 0, 1}};

    int colunas = dfy/2;

    a %= 4; if(a < 0) a+=4;
    c %= 4; if(c < 0) c+=4;
    b %= 2; if(b < 0) b+=4;
    d %= 2; if(d < 0) d+=4;

    for(int j = b; j != d; j = (j+1)%2)
        for(int i = a; i != c; i = (i + 1)%4){
            area += mat[j][i];
        }


    cout << area << "\n";
}