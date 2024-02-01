#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    s.push_back('?');

    for(int i = 0; i < n;)
    {   
        if(i != 0)cout << '.';
        if(i + 3 >= n){
            cout << s[i] << s[i+1];
            if(i + 2 < n)cout << s[i+2];
            break;
        }
        else if(s[i + 3] == 'a' || s[i + 3] == 'e'){cout << s[i] << s[i+1];i = i + 2;}
        else {cout << s[i] << s[i+1] << s[i+2]; i = i + 3;}
    }
    cout << endl;
}


int main(){
    fastio;
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    
    

}