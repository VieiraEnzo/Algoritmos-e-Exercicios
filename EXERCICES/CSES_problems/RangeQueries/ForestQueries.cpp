#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr); ios_base::sync_with_stdio(0);

    int n, q; cin >> n >> q;
    vector m(n, vector<int> (n));
    vector pref(n, vector<int> (n));

    for(int i = 0; i< n; i++)
        for(int j = 0; j < n; j++){
            char temp; cin >> temp;
            pref[i][j] = temp == '*'? 1 : 0;
        }

    for(int i = 1; i< n; i++)
        pref[i][0] += pref[i-1][0];
    for(int i = 1; i < n; i++)
        pref[0][i] += pref[0][i-1];

    for(int i = 1; i < n; i++)
        for(int j = 1; j < n; j++)
            pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];

    // for(int i = 0; i < n; i++){
    //         for(int j = 0; j < n; j++){
    //             cout << pref[i][j];
    //     }cout << "\n";}

    while (q--)
    {
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--;y1--;x2--;y2--;
        int ans = pref[x2][y2];
        if(x1 != 0 && x2 != 0)ans -= pref[min(x1,x2) - 1][max(y1,y2)];
        if(y1 != 0  && y2 != 0)ans -= pref[max(x1,x2)][min(y1,y2)-1];
        if(x1 != 0 && x2 != 0 && y1 !=0  && y2 != 0)ans += pref[min(x1,x2)-1][min(y1,y2)-1];
        cout << ans << "\n";
    }
    

            


}