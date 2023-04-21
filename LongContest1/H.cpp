#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,s,m;
    int array[50];
    cin >> n;


    for(int i = 0 ; i < 5; i ++){
        cin >> m >> s;
        for(int j = 0; j < m;j++){
            cin >> array[j];
        }
        
        int k = 1,prev;
        bool found,complete;

        while(s > 0)
        {
            found = false;
            for(int i = 0; i < m;i++){
                if(array[i] == k){
                    found = true;
                    break;}
            }
            if(!found){s -= k;}
            if(s == 0){break;}
            k++;
        }

        if(s==0 && complete){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}
