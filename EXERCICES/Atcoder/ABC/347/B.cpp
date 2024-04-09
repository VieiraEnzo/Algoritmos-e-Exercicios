#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s; cin >> s;
    vector<ll> v(s.size());
    set<string> st;

    for(int i = 0; i < s.size(); i++){
        for(int j = 1; i + j <= s.size(); j++){
            st.insert(s.substr(i,j));
        }
    }

    cout << st.size() << endl;

    
}