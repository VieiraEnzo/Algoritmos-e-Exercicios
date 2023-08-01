#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    vector<string> map(M);
    for (int i = 0; i < M; i++)
        cin >> map[i];
    queue<pair<int, int>> fila;
    int visited[M][N];
    int pontos_visitados[M][N];
    for(int i =0; i< M; i++){
        for(int j =0; j< N; j++){
            visited[i][j] = 0;pontos_visitados[i][j] = 0;
        }
    }
        

            
    fila.push(make_pair(1, 1));
    int total = 0;
    visited[1][1] = 1;
    int contagem = 0;

    while (!fila.empty())
    {

        int x = fila.front().first;
        int y = fila.front().second;
        fila.pop();

        int i = x, j = y;
        while (map[i - 1][j] != '#')
        {
            if (pontos_visitados[i - 1][j] == 0)
            {
                pontos_visitados[i - 1][j] = 1;
                contagem++;
            }
            i--;
        }
        if (visited[i][j] != 1)
        {
            fila.push(make_pair(i, j));
            visited[i][j] = 1;
        }

        i = x, j = y;
        while (map[i + 1][j] != '#')
        {
            if (pontos_visitados[i + 1][j] == 0)
            {
                pontos_visitados[i + 1][j] = 1;
                contagem++;
            }
            i++;
        }
        if (visited[i][j] != 1)
        {
            fila.push(make_pair(i, j));
            visited[i][j] = 1;
        }

        i = x, j = y;
        while (map[i][j - 1] != '#')
        {
            if (pontos_visitados[i][j - 1] == 0)
            {
                pontos_visitados[i][j - 1] = 1;
                contagem++;
            }
            j--;
        }
        if (visited[i][j] != 1)
        {
            fila.push(make_pair(i, j));
            visited[i][j] = 1;
        }

        i = x, j = y;
        while (map[i][j + 1] != '#')
        {
            if (pontos_visitados[i][j + 1] == 0)
            {   
                pontos_visitados[i][j + 1] = 1;
                contagem++;
            }
            j++;
        }
        if (visited[i][j] != 1)
        {
            fila.push(make_pair(i, j));
            visited[i][j] = 1;
        }
    }

    cout << contagem;
}
