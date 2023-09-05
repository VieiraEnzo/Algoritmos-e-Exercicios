#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int t, size;
    bool no;
    string word;
    cin >> t;
    
    for(int init = 0; init < t; init++){
        no = true;
        cin >> size >> word;
        for(int i=0; i < size -1; i++){
            for(int j = i+1; j < size; j ++){
                if(word[i]==word[j]){
                    if(((j-i-1) % 2) == 0 && no){
                        cout << "NO" << endl;
                        no = false;
                    }
                }
            }
        }
        if(no){cout << "YES" << endl;}
        
    }

}




