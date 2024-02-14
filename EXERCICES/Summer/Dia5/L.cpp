#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n; cin >> n;
    vector<pair<pair<int,int>,int>> ri(n);

    for(int i =0 ; i < n; i++){
        int s, r; cin >> s >> r;
        ri[i] = {make_pair(r,s), i};
    }

    sort(ri.rbegin(), ri.rend());

    int maxs = -1;
    int rdmax = -1;
    int empPrim = ri[0].first.first;
    vector<int> resp(n);

    for(auto a : ri){
        int r = a.first.first;
        int s = a.first.second;
        int i = a.second;
        

        if(s > maxs){
            maxs = s;
            rdmax = r;
            resp[i] = 1;
        }
        
        //check if are equal
        if(s == maxs && rdmax == r){
            resp[i] = 1;
        }

    }

    for(int i= 0; i< n; i++){
        if(resp[i]) cout << i + 1 << " ";
    }cout << endl;

    

}