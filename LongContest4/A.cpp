#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int n;
    int input;
    set<int> order;
    cin >>n;

    for(int i=0;i<n;i++){
        cin >> input;
        order.insert(input);
    }

    
    if(order.size() > 1){
        set<int>::iterator it = order.begin();
        it ++;
        cout << *(it);
    }
    else{
        cout << "NO";
    }
    
}
