#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define INF 1e9
typedef long long ll;


int main(){
    fastio;
    string a; cin >> a;
    char last  = a[0];
    int ans = 1;
    int now =1;
    for(int i =1; i < a.size(); i++){
        if(a[i] == last){
            now++;
        }
        else{
            now = 1;
            last = a[i];
        }
        ans = max(ans, now);
    }
    cout << ans << endl;

}