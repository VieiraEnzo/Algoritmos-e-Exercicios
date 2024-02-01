#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    int N; cin >> N;
    vector<string> v(N);
    for(int i =0; i < N; i ++) cin>> v[i];

    for(int i=0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            if(i == j) continue;
            string nova = v[i] + v[j];
            bool palin = true;

            int k=0, l =nova.size()-1;
            while (k<l)
            {   
                if(nova[k] != nova[l]){
                    palin = false;
                    break;
                }
                k++;
                l--;
            }

            if(palin){
                cout << "Yes";
                return 0;
            }
            

        }
    }
    cout << "No";

}
    