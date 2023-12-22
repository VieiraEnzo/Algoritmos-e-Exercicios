#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;



int main(){
    //fastio;
    map<int,int> mp;
    int n,m; cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        int temp; cin >> temp;
        mp[temp] = i;
    }

    ll ans = 1;
    for(int i = 2 ; i <= n ; i++)
    {
        if(mp[i-1] > mp[i]){ans++;}
    }
    
    while (m--)
    {
        int x,y; cin >> x >> y;
        int desl = 0;

        if(x != 1 && mp[x-1] < mp[x] && mp[x-1] > mp[y]){desl++;}
        if(x!= 1 && mp[x-1] > mp[x] && mp[x-1] < mp[y]){desl--;}
        else if(x != 5 && mp[x+1] > mp[x] && mp[x+1] < mp[y]){desl++;}
        else if(x != 5 && mp[x+1] < mp[x] && mp[x+1] > mp[y]){desl--;}

        if(y != 1 && mp[y-1] < mp[y] && mp[y-1] > mp[x]){desl++;}
        if(y != 1 && mp[y-1] > mp[y] && mp[y-1] < mp[x]){desl--;}
        else if(y != 5 && mp[y+1] > mp[y] && mp[y+1] < mp[x]){desl++;}
        else if(y != 5 && mp[y+1] < mp[y] && mp[y+1] > mp[x]){desl--;}

        int temp = mp[x];
        mp[x] = mp[y];
        mp[y] = temp;

        ans += desl;
        cout << ans << endl;
    }
    

}