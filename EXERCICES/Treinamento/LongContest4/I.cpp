#include <bits/stdc++.h>
#include <vector>
using namespace std;


int main(){
    set <int> numeros;
    int n,temp;
    scanf("%d",&n);
    for(int i =0; i< n; i ++){
        scanf("%d",&temp);
        numeros.insert(temp);
    }
    printf("%d", numeros.size());
}
