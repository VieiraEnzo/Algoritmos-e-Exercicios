#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, Q, call;
    cin >> N >> Q;
    bool called[N+1];
    auto it = called;
    int last = 0;
    for(int i =0; i < Q; i ++){
        cin >> call;
        if(call == 1){
            called[last] = false;
            last+=1;
        }
        if(call == 2){
            int x;
            cin >> x;
            called[x-1] = true;
        }

        if(call == 3){
            while (*it == true){it -= 1*sizeof(bool);}
            *it = true;
            cout << called - it + 1 << endl;
            it += 1;
        }
    }
}
    

