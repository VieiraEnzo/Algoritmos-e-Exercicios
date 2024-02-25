#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int f(int v){

    int i = 0;
    while (v != 0)
    {   
        i++;
        v/=10;
    }
    return i;
}

void remove_equal(multiset<int> &A, multiset<int> &B){

    queue<int> rem;

    for(auto i = A.begin(); i != A.end(); i++){
        auto j = B.find(*i);
        if(j != B.end()){
            B.erase(j);
            rem.push(*i);
        }
    }
    while (!rem.empty())
    {
        int p = rem.front();
        rem.pop();
        A.erase(A.find(p));
    }
}


void solve(){
    int n; cin >> n;

    multiset<int> A, B;
    
    vector<int> cntA(10);
    vector<int> cntB(10);

    for(int i = 0; i < n; i++){
        int v;cin >> v;
        A.insert(v);
    }

    for(int i = 0; i < n; i++){
        int v;cin >> v;
        B.insert(v);
    }


    remove_equal(A,B);

    int ans = 0;

    for(int i : A){
        if(i > 9){i = f(i);ans++;}
        cntA[i]++;
    }
    for(int i : B){
        if(i>9){i = f(i);ans++;}
        cntB[i]++;
    }


    for(int i = 0; i< 10; i++){
        int p = min(cntA[i], cntB[i]);
        cntA[i] -= p;
        cntB[i] -= p;
    }

    for(int i = 2; i < 10; i++){
        ans += cntA[i];
        ans += cntB[i];
    }

    cout << ans << endl;
    
}



int main(){
    
    fastio;
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    


    

}