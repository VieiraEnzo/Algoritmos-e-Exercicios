#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> marc(16);
vector<int> subconjunto;
int ans = 0;

void sub(){
    if(subconjunto.size() == 6){
        for(auto a : subconjunto){
            cout << a << " ";
        }cout << endl;
        return;
    }
    for(int i = 1; i <= 6; i++){
        if(marc[i] == 1) continue;
        marc[i] = 1;
        subconjunto.push_back(i);
        sub();
        marc[i] = 0;
        subconjunto.pop_back();
    }
}


int main(){

    sub();

}