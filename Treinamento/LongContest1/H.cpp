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
        
        int k = 1;
        int last = 0;
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
            if(s == 0){
                last = k;
                break;}
            k++;
        }
       
       
        int higher = array[0];
        for(int i=1; i < m; i++){
            if(array[i] > higher){higher = array[i];}}

        complete = true;
        if(last > higher){}
        else{
            int in_betwen = 0;
            for(int i = last + 1; i < higher; i++){
                for(int j=1; j < m; j++){
                    if(array[j] == i){
                        in_betwen ++;
                        continue;}
                }
            }
            if(in_betwen != higher - last -1){complete = false;}
        }

        if(s==0 && complete){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}
