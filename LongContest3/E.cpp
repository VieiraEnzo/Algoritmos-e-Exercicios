#include <bits/stdc++.h>
#include <vector>
using namespace std;

int lowest_not_called(bool *insert, int N){
    for(int i =0; i <N;i++){
        if(insert[i] == false){
            insert[i] = true;
            return i + 1;
        }
    }
    return -1;
}


int main(){
    int N,Q,event,id;
    cin >> N >> Q;
    bool insert[N];
    vector<int> called;

    for(int i =0;i < N; i++){
        insert[i] = false;
    }

    for(int i =0;i < Q; i++){
        cin >> event;
        switch (event)
        {
        
        case 1:
            called.push_back(lowest_not_called(insert,N));
            break;

        case 2:
            cin >> id;
            //find element in called
            for(int i=0; i < called.size(); i++){
                if (called[i] == id){
                    called.erase(called.begin() + i);
                }
            }
            break;
            
        case 3:
            cout << called[0] << endl;
            break;
        }



    }

}
