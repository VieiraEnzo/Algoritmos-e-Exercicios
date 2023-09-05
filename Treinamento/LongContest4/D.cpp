#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct point
{
    int x;
    int y;
};

bool sort_point(struct point i, struct point j){
    if(i.x == j.x) return (i.y > j.y);
    else return (i.x < j.x);
}


int main(){
    int t;
    scanf("%d",&t);
    for(int init =0; init < t; init ++){
        int n, num;
        struct point temp;
        scanf("%d",&n);
        vector <point> ponto;
    
        for(int i=0;i < n; i ++){
            scanf("%d",&num);
            temp.x = num;
            scanf("%d",&num);
            temp.y = num;
            ponto.push_back(temp);
        }
        
        sort(ponto.begin(), ponto.end(), sort_point);
        
        for(int i =0; i < n; i ++){
            printf("%d %d \n", ponto[i].x, ponto[i].y);
        }
    }

}   
