#include <bits/stdc++.h>
#include <vector>
using namespace std;

int bSearch(vector <int> &numeros, int e, int d, int x){
    if(x < numeros[0]) return -1;
    int mid;
    while(e<=d){
        mid = (e+d)/2;
        
        if(numeros[mid] == x){
            d = mid;
        }
        else if(numeros[mid] < x){
            e = mid + 1;
        }
        else{
            d = mid - 1;
        }
    }
    return mid -1;
}


int main(){
    int n,q,num;
    vector <int> prices;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &num);
        prices.push_back(num);
    }

    sort(prices.begin(),prices.end());

    scanf("%d", &q);
    for(int i = 0; i < q; i ++){
        scanf("%d", &num);
        printf("%d\n",bSearch(prices, 0, prices.size(), num) + 1);
    }
}
