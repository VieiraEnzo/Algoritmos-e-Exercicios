#include <bits/stdc++.h>
using namespace std;


int main(){
    unsigned long long int A,B;
    cin >> A >> B;
    unsigned long long int i=0;
    while (A != B){
        

        if(A>B){
            if(A%B == 0){
                i+= A/B - 1;
                break;
            }
            i += (A/B);
            A = A - (A / B) * B;
        }
        else{
            if(B%A == 0){
                i+= B/A - 1;
                break;
            }
            i += (B/A);
            B = B - (B / A) * A;
        }

    }
    cout << i;
}   