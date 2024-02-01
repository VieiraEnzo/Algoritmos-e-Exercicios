#include <bits/stdc++.h>
using namespace std;
int contagem = 0;

bool clear_from_queens(pair<int,int> point , vector<pair<int,int>> &queens){
    for(int i =0; i < queens.size(); i++){
        if(abs(queens[i].first - point.first) == abs(queens[i].second - point.second)){
            return false;
        }
        else if(queens[i].first == point.first || queens[i].second == point.second){
            return false;
        }
    }
    return true;

}

void queens_in_mathc(int line, char map[8][8], vector<pair<int,int>> &queens){
    //int count = 0;
    for(int i=0; i < 8; i ++){
        //for(int i =0; i < queens.size(); i++){cout << '('<< queens[i].first <<','<< queens[i].second << ')' << endl;}
        pair<int,int> point = {line,i};
        if(line == 7 && clear_from_queens(point,queens) && map[line][i] == '.'){contagem++;continue;}
        else if(line == 7){continue;}
        else if(map[line][i] == '.' && clear_from_queens(point,queens)){
            //printf("Cabe uma rainha no ponto %d %d \n",point.first,point.second);
            queens.push_back(point);
            //count += queens_in_mathc(line+1,map,queens);}
            queens_in_mathc(line+1,map,queens);
            queens.pop_back();}
        //printf("Não cabe uma rainha no ponto %d %d \n",point.first,point.second);
    }
    //printf("Fim do nivel %d \n",line);
    //return count;
}


int main(){
    char map[8][8];
    vector<pair<int,int>> queens;
    for(int i =0; i < 8; i ++){
        cin >> map[i];
    }
    queens_in_mathc(0,map,queens);
    cout << contagem;


}