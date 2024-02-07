#include <bits/stdc++.h>
using namespace std;



void solve(){
    int n, m, k; cin >> n >> m >> k;
    map<int,int> hasA;
    map<int,int> hasB;

    for(int i = 0; i < n ; i++){
        int temp; cin >> temp;
        hasA[temp] = 1;
    }
    for(int i = 0; i < m; i++){
        int temp; cin >> temp;
        hasB[temp] = 1;
    }

    int obA = 0;
    int obB = 0;
    int both = 0;
    bool impossible = false;

    for(int i = 1; i <= k; i++){
        if(hasA[i] == 1 && hasB[i] == 1) both++;
        else if (hasA[i])obA++;
        else if (hasB[i])obB++;
        else{
            impossible = true;
        }
    }

    if(impossible || abs(obA - obB) > both){
        cout << "NO" << "\n";
    }else{
        cout << "YES" << "\n";
    }


}

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    
}