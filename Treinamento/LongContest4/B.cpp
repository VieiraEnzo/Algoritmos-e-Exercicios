#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int n;
    int input;
    multiset<int> order;
    cin >>n;

    for(int i=0;i<n;i++){
        cin >> input;
        order.insert(input);
    }
    
    if(n % 2 == 0){
        multiset<int>::iterator it = order.begin();
        for(int i =1 ; i < n/2; i ++){
            it++;
        }

        cout << *it;
        
    }
    else{
        multiset<int>::iterator it = order.begin();
        for(int i =0 ; i < n/2; i ++){
            it++;
        }
        cout << *it;

    }
    
}
