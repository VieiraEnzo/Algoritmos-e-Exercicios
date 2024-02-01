#include <bits/stdc++.h>
#include <vector>
using namespace std;

void more_than_all(vector<int> &CubeTower, int cube){
    bool entered = false;
    for(int i =0; i < CubeTower.size(); i ++){
        if(cube < CubeTower[i]){
            CubeTower[i] = cube;
            entered = true;
            break;
        }
    }
    if(!entered){
        CubeTower.push_back(cube);
    }
}


int main(){
    int n, cube;
    cin >> n;
    vector <int> CubeTower;

    cin >> cube;
    CubeTower.push_back(cube);
    for(int i=1;i<n;i++){
        cin >> cube;
        more_than_all(CubeTower, cube);
    }

    cout << CubeTower.size();
}
