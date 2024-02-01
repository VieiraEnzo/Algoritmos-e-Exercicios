#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
vector<int> code;
int n;


int main(){
    fastio;
    int n; cin >> n;
    code.resize(n);
    fill(code.begin(),code.end(),0);
    
    for(int i =0; i < n; i++){
        code[i] = 1;
    }

}