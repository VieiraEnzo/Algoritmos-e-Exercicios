#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n, pos, c; cin >> n >> pos >> c;
    cout << ((--pos + c)%n)+1 << endl;

}