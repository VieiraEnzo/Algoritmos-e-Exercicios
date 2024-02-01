#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int t;
    cin >> t;
    string friends;

    for(int init = 0;init < t; init++){
        cin >> friends;
        long long int ladrao = 0,ultimo_1 = 0, primeiro_0 = friends.size() -1;

        for(int i=0 ;i<friends.size();i++){
            if(friends[i] == '1'){
                ultimo_1 = i;
            }
            else if(friends[i] == '0'){
                primeiro_0 = i;
                break;
            }
        }

        cout << primeiro_0 - ultimo_1 + 1 << endl;
        

    }


}
