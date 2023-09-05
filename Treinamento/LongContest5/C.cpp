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

    //PROBLEMA: Algortimo n^3;
    //OPÇÃO: Ordenar e fazer busca binária
    int count = 0;
    for(int i = 0;i < n -1; i++){
        for(int j = i+1;j < n; j++){
            for(int k = 0; k < n; k ++){
                if(k == i || k == j){continue;}
                if((float)(points[i].first + points[j].first)/2 == points[k].first && (float)(points[i].second + points[j].second)/2 == points[k].second){
                    count++;
                }
            }      
        }
    }
    cout << count;
    }
