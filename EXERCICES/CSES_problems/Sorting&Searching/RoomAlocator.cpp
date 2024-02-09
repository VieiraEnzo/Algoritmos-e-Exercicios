#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n; cin >> n;
    vector<pair<pair<int,int>,int>> ord(2*n);
    vector<int> chave(n, -1);
    stack<int> torre;

    for(int i = 0; i < 2 * n; i+= 2){
        int cheg, part; cin >> cheg >> part;
        ord[i] = {make_pair(cheg, 0), i/2};
        ord[i+1] = {make_pair(part, 1), i/2};
    }

    sort(ord.begin(), ord.end());
    for(int i = n; i >=1; i--)torre.push(i);

    int ans = 0;
    int now = 0;
    for(int i = 0; i< 2*n; i++){
        if(ord[i].first.second == 1){
            torre.push(chave[ord[i].second]);
            now--;
        }else{
            chave[ord[i].second] = torre.top();
            torre.pop();
            now++;
        }
        ans = max(ans, now);
    }

    cout << ans << endl;
    for(int i = 0; i < n; i++){
        cout << chave[i] << " ";
    }cout << endl;

}