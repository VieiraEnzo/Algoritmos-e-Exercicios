#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;



int main(){
    fastio;
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int x = 0;
        int minE = 1e9, maxE = 0;
        for(int i = 0; i < n; i++){
            int temp; cin >> temp;
            minE = min(temp, minE);
            maxE = max(temp, maxE);
        }
        int maxD = maxE - minE;
        int ans = log2(maxD);
        if(maxD == 0){cout << 0 << endl; continue;}
        cout << ans + 1<< endl;
        if(ans+1 <= n){
            for(int i = 0; i < ans + 1; i++) cout << minE << " ";
            cout << endl;
        }

    }
    

    

}