#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    pair<int,int> temp;
    cin >> n;
    vector<pair<int,int>> points;
    for(int i = 0; i < n; i++){
        cin >> temp.first >> temp.second;
        points.push_back(temp);
    }
    int count = 0;
    for(int i = 0;i < n -2; i++){
        for(int j = i+1;j < n -1; j++){
            for(int k = j+1;k < n; k++){
                if((points[i].first - points[j].first) == 0 || (points[i].first - points[k].first) == 0){continue;}
                if((points[i].second - points[j].second)/(points[i].first - points[j].first) == (points[i].second - points[k].second)/(points[i].first - points[k].first)){
                    // cout << points[i].first << " "<< points[j].first << " "<< points[k].first << " " << endl;
                    count++;
                }
            }
        }
    }
    cout << count;
}