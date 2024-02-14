#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int f(int a){
    int size = 0;
    while (a != 0)
    {
        size++;
        a /= 10;
    }
    
    return size;
}


void solve(){

    map<int,int> freq;

    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i< n; i++) cin >> a[i];
    for(int i = 0; i< n; i++) cin >> b[i];

    //sort baseado no:
    //numero de digitos / qual é o digito

    int ans = 0;
    for(int i = 0; i < n; i++){
        while (a[i] != b[i])
        {
            if(a[i] < b[i]) b[i] = f(b[i]);
            else a[i] = f(a[i]);
            ans++;
        }
        
    }

    cout << ans << endl;
}



int main(){
    fastio;
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    


    

}