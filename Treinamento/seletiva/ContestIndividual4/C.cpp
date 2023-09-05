#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, D;
    string temp;
    vector<int> days;
    cin >> N >> D;
    for(int j =0; j < D; j++){
            days.push_back(0);
        }
    for(int i =0; i < N; i++){
        cin >> temp;
        for(int j =0; j < D; j++){
            if(temp[j] == 'o'){
                days[j] += 1;
            }
        }
    }


    int maxim = 0 ,prev,now = 0;
    bool some_D = false;
    for(int i =0;i < D; i++){
        if(days[i] == N){
            now += 1;
        }
        else{
            now = 0;
        }
        maxim = max(now, maxim);
    }


    cout << maxim;


}
    

