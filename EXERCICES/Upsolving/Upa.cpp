#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

bool compare(pair<int,char> bus1, pair<int,char> bus2){
    if(bus1.first == bus2.first){
        if(bus1.second == 'E'){
            return false;
        }
        return true;
    }
    else{
        return bus1.first > bus2.first;
    }
}


int main(){
    fastio;
    int n; cin >> n;
    vector<pair<int,char>> bus;
    for(int i = 0; i < n; i ++){
        int temp1,temp2;
        cin >> temp1 >> temp2;
        bus.push_back(make_pair(temp1,'E'));
        bus.push_back(make_pair(temp2,'S'));
    }
    sort(bus.begin(),bus.end(),compare);
    
    int ans = 1;
    int now = 0;
    for(int i =0; i < bus.size(); i++){
        if(bus[i].second == 1){
            now++;
        }
        else{
            now--;
        }
        ans = max(ans,now);
    }
    cout << ans * 20 << endl;

}