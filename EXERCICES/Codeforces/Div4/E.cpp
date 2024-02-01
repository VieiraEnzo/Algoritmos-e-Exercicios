#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve()
{
    int n; cin >> n;
    //recieve
    vector<ll> somaAlternada(n);
    map<ll, int> ExisteSoma;
    ExisteSoma[0] = 1;
    ll sum = 0;
    bool solved = false;
    for(int i= 0; i < n; i++)
    {
        int temp; cin >> temp; 
        if(i%2)temp = -temp;
        sum += temp;
        somaAlternada[i] = sum;

        if(!solved && ExisteSoma[somaAlternada[i]])
        {
            cout << "YES" << endl;
            solved = true;
        }

        ExisteSoma[sum] = 1;

    }
    if(!solved)cout << "NO" << endl;

}

int main(){
    fastio;
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    
    

}