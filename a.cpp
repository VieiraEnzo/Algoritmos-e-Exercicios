#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, t; cin >> n >> t;
    vector<ll> QtsAtingem(n+1), QtsPodeAtingir(n+1);
    ll Qa = 0, Qpa = 0;
    ll MQaQpa = 0;

    ll Reachable = 0;

    while(t--){
        int a,b; cin >> a >> b;

        Reachable -= QtsAtingem[b] * QtsPodeAtingir[b];
        if(a != b) Reachable -= QtsAtingem[a] * QtsPodeAtingir[a];

        QtsAtingem[b]++;
        Qa = max(Qa, QtsAtingem[b]);
        QtsPodeAtingir[a]++;
        Qpa = max(Qpa, QtsPodeAtingir[a]);

        MQaQpa = max(MQaQpa, QtsAtingem[b]+QtsPodeAtingir[b]+1);
        MQaQpa = max(MQaQpa, QtsAtingem[a]+QtsPodeAtingir[a]+1);

        Reachable += QtsAtingem[b] * QtsPodeAtingir[b] ;
        if(a != b) Reachable += QtsAtingem[a] * QtsPodeAtingir[a];

        cout << Reachable << " " << max({Qa + Qpa, MQaQpa}) << "\n";
    }
}