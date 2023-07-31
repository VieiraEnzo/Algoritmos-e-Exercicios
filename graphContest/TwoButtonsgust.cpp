#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    int m,n; cin >> n >> m;
    queue <pair<int,int>> line;
    line.push(make_pair(0,n));
    bool seen[20001];
    for(int i =0; i < 20001; i ++) seen[i] = false;

    while(!line.empty()){
        int i = line.front().first;
        int x = line.front().second;
        line.pop();

        if(seen[x]){continue;}
        else{seen[x] = true;}
        
        if(x == m){cout << i << endl;return 0;}

        if(x < m)line.push(make_pair(i+1, x*2));
        if(x >= 2) line.push(make_pair(i+1, x-1));

        }


}