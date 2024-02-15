#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n, m; cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);
    vector<int> S(n+1);

    for(int i = 0; i < n; i++)cin>>A[i];
    for(int i = 0; i < m; i++)cin>>B[i];

    for(int i = 0; i< m; i++){
        int b = B[i];
        int comp = b/n;
        S[0] += comp;
        S[n] -= comp;
        if(comp != 0) b = b%comp;
        S[0] += 1;
        S[b+1] -= 1;  
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += S[i];
        S[i] = sum;
        
        cout << S[i] + A[i] << " ";
    }cout << endl;

}