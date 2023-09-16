#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
#define f first
#define sec second

int main(){
    fastio;
    ll n,m; cin >> n >> m;
    vector<pair<ll,ll>> p(n+1);
    vector<bool> det(n+1);
    fill(det.begin(), det.end(), false);
    p[1] = {0,0};
    det[1] = true;


    while (m--)
    {
        ll a,b,x,y;
        cin >> a >> b >> x >> y;
        if(det[a])
        {
            p[b] = make_pair(p[a].f + x , p[a].sec + y);
            det[b] = true;
        }
        else if(det[b])
        {
            p[a] = make_pair(p[b].f - x , p[b].sec - y);
            det[a] = true;
        }
        
    }
    
    for(ll i =1; i <n+1; i++)
    {
        if(!det[i]) cout << "undecidable" << endl;
        else cout << p[i].f << " " << p[i].sec << endl;
    }
    

}