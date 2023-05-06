#include <bits/stdc++.h>
using namespace std;

struct card{

    long long int color;

    long long int rank;

};

int main(){

    long long int N,T,temp;

    cin >> N >> T;

    struct card cards[N];

    for(int i =0; i < N; i++){

        cin >> cards[i].color;

    }

    for(int i = 0; i < N; i++){

        cin >> cards[i].rank;

    }

    long long int winner_color_1 = 0,winner_color_t;

    bool someone_T = false;

    for(int i = 0; i < N; i++){

        if(cards[i].color == T){

            if(!someone_T){

                someone_T = true;

                winner_color_t = i;

            }

            else if(cards[i].rank > cards[winner_color_t].rank) winner_color_t = i;


        }

        if(cards[i].color == cards[0].color){

            if(cards[i].rank > cards[winner_color_1].rank){

                winner_color_1 = i;

            }

        }

    }
    if(someone_T){
        cout << winner_color_t + 1;
    }
    else{
        cout << winner_color_1 + 1;
    }

}