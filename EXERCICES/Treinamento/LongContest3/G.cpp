#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,how_many=0;
    cin >> N;
    int vec[N];
    bool called[N];

    for(int i=0; i < N; i++){
        cin >> vec[i];
        called[i] = false;
    }

    for(int i=0; i < N; i++){
        if(called[i]){
            continue;            
        }
        else{
            called[vec[i]-1] = true;
        }
    }

    for(int i=0; i < N ;i++){
        if(!called[i]){how_many++;}
    }

    cout << how_many << endl;

    for(int i=0; i < N ;i++){
        if(!called[i]){cout << i+1 << ' ';}
    }


}
