#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,size;
    char letter;
    cin >> n;
    for(int init = 0; init < n; init ++){
        cin >> size;
        int max = 1;
        for(int i =0; i < size; i ++){
            cin >> letter;
            if(letter - 'a' + 1 > max){
                    max = letter - 'a' + 1;
            }
        }
        cout << max << " " << endl;
    }   
    }
  
    

