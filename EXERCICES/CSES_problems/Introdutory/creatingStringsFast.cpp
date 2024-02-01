#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)

int main(){
    fastio;
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    vector<string> v;
    do{
        v.push_back(s);
    }
    while(next_permutation(s.begin(), s.end()));
    sort(v.begin(),v.end());
    cout << v.size() << endl;
    for(auto a : v){
        cout << a << endl;
    }
}