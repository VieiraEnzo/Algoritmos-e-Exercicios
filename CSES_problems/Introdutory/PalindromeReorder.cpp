#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    string s; cin >> s;
    sort(s.begin(), s.end());
    char mid;
    bool first = true;
    for(int i =0; i < s.size(); i+=2)
    {
        if(s[i] != s[i+1]){
            if(first)
            {
                mid = s[i];
                first = false;
                i--;
            }
            else if(!first)
            {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }

    }

    for(int i =0; i < s.size(); i+=2)
    {
        cout << s[i];
    }
    if(first) cout << mid;
    for(int i = s.size()-1; i>=0; i-=2)
    {
        cout << s[i];
    }


}