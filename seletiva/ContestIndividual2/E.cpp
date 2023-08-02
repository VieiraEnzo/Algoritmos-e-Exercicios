#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    int N, D; cin >> N >> D;
    vector<pair<int,int>> v(N);
    vector<bool> infected(N);
    for(int i=0; i< N;i ++) infected[i] = false;
    infected[0] = true;
    for(int i=0; i< N;i ++){
        int x,y; cin>> x >> y;
        v[i] = make_pair(x,y);
    }
    queue<pair<int,int>> virus;
    virus.push(v[0]);
    while (!virus.empty())
    {
        int x = virus.front().first;
        int y = virus.front().second;
        virus.pop();

        for(int i=0; i < N; i++){
            if(infected[i]) continue;
            if(sqrt((x-v[i].first)*(x-v[i].first) + (y-v[i].second)*(y-v[i].second)) <= D){
                infected[i] = true;
                virus.push(v[i]);
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(infected[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
}
    