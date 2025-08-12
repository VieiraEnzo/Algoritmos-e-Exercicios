#include<bits/stdc++.h>
using namespace std;

int main(){
    int e, s, l; cin >> e >> s >> l;
    cout << 2*(max({s,l,e}) - min({s,l,e})) << "\n";

}