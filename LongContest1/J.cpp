#include <bits/stdc++.h>
using namespace std;


int main(){
    int t,n,s,r;
    int array[50];
    cin >> t;

    for(int i = 0 ; i < t; i ++){
        cin >> n >> s >> r;
        cout << s - r << ' ';
        int loops = 1;
        while (true)
        {   
            if(r % (n-loops) == 0){
                for(int i =0; i < n-loops; i++){
                    cout << r/(n-loops) << ' ';
                }
                break;
            } 
            else{
                cout << r/(n-loops) << ' ';
                r -= r/(n-loops);
                loops ++;
            }
        }
        cout << endl;
    }
}
