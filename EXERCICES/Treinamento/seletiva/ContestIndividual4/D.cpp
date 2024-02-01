#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int A,B;
    cin >> A >> B;
    if(A%B != 0){
        cout << (A/B) + 1;
    }
    else{
        cout << A/B;
    }
}
    

