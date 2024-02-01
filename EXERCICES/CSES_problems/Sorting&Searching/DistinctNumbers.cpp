#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    set<int> s;
    int n; cin >> n;
    for(int i =0; i <n; i ++){
        int temp; cin >> temp;
        s.insert(temp);
    }
    cout << s.size() << endl;

}