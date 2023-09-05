#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    int N,P,Q; cin >> N >> P >> Q;
    vector <int> price(N);
    for(int i =0; i < N; i ++) cin >> price[i];
    sort(price.begin(),price.end());
    cout << min(P,Q+price[0]) << endl;
}
    