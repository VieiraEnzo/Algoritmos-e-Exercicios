#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct Point{
    double x, y;
};


double dist(Point a, Point b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}


int main(){
    fastio;
    int n; cin >> n;
    vector<Point> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].x >> v[i].y;
    }
    
    for(int i = 0; i < n; i++){
        int id = -1;
        double distL = 0;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(dist(v[i], v[j]) > distL){
                id = j;
                distL = dist(v[i], v[j]);
            }
        }
        cout << id  + 1<< endl;
    }

}