#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
int maxn = 2e5 + 5;
vector<vector<int>> sparce(32, vector<int>(maxn));

int main(){
    int n, q; cin >> n >> q;
    
    for(int i = 0; i< n; i++)cin >> sparce[0][i];
    for(int i = 1; i < 32; i++){
        for(int j = 0; j < n; j++){
            sparce[i][j] = sparce[i-1][j];
            if(j + (1<<(i-1)) < n)
                sparce[i][j] = min(sparce[i-1][j] , sparce[i-1][j + (1<<(i-1))]);
        }
    }


    // for(int i = 0; i< n; i++)
    //     cout << sparce[0][i] << " ";

    while (q--)
    {
        int a, b; cin >> a >> b;
        int dif = max(a,b) - min(a,b) + 1;
        a--; b--;
        
        //max bit
        int maxbit = 0;
        for(int i = 0 ; i <32; i++){
            if((1<<i) & dif){
                maxbit = i;
            }
        }
        
        // cout << sparce[maxbit][a] << " " <<  sparce[maxbit][b-(1<<maxbit)] << endl;
        cout << min(sparce[maxbit][a], sparce[maxbit][b-(1<<maxbit) + 1]) << endl;
        
    }
    

}