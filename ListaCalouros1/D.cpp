#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int main(){
    fastio;
    int n,c; cin >> n >> c;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin >> v[i];
    sort(v.begin(),v.end());
    int ovos =0;
    for(int i =0; i< n; i++){
        if(c - v[i] >=0){c-=v[i]; ovos++;}
        else break;
    }
    cout << ovos;
}
