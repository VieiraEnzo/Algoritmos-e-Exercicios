#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;



int main(){
    //fastio;
    int n,m; cin >> n >> m;
    vector<int> mp(n+1);
    vector<int> v(n+1);
    for(int i = 1 ; i <= n ; i++)
    {
        int temp; cin >> temp;
        mp[temp] = i;
        v[i] = temp;
    }

    vector<int> resp(n+1);

    ll ans = 1;
    for(int i = 2 ; i <= n ; i++)
    {
        if(mp[i-1] > mp[i]){
            resp[i] = 1;
            ans++;
        }
    }

    
    while (m--)
    {
        int a,b; cin >> a >> b;
        int x = v[a];
        int y = v[b];


        if(mp[x-1] > mp[x] && !(mp[x-1] > mp[y])){ans--;}
        if(!(mp[x-1] > mp[x]) && (mp[x-1] > mp[y])) ans++;
        if(mp[x+1] > mp[x+1] && !(mp[y] > mp[x+1])){ans--;}
        if(!(mp[x] > mp[x+1]) && (mp[y] > mp[x+1])) ans++;
        
        if(mp[y-1] > mp[y] && !(mp[y-1] > mp[x])) ans--;
        if(!(mp[y-1] > mp[y]) && (mp[y-1] > mp[x])) ans++;
        if(mp[y] > mp[y+1] && !(mp[x] > mp[y+1])) ans--;
        if(!(mp[y] > mp[y+1]) && (mp[x] > mp[y+1])) ans++;
        
        swap(mp[x], mp[y]);
        swap(v[a], v[b]);
        cout << ans << endl;
    }
    

}