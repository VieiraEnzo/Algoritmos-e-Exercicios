#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool func(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main(){
    fastio;
    int n; cin >> n;
    vector<pair<int,int>> cards(n);
    vector<pair<int,int>> copy(n);
    for(int i = 0; i < n; i++) {cin >> cards[i].second >> cards[i].first; copy[i] = cards[i];}

    sort(all(cards), func);

    // for(int i = 0; i < n; i++){
    //     cout << cards[i].first << " " << cards[i].second << "\n";
    // }

    set<int> remove;

    int maxA = 0;
    for(int i = 0; i < n; i++){
        int cost = cards[i].first;
        int pow = cards[i].second;
        if(pow < maxA){remove.insert(i);}
        maxA = max(pow, maxA);
    }

    set<pair<int,int>> s;
    for(int i = 0; i < n; i++){
        if(remove.find(i) == remove.end()){
            s.insert(cards[i]);
        }
    }

    cout << s.size() << "\n";

    for(int i = 0; i < n; i++){
        if(s.find(copy[i]) != s.end()){
            cout << i+1 << " ";
        }
    }cout << "\n";

}