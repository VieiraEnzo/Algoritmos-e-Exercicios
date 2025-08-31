#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
⣀⣀⠀⠀⠀⠀⠀⠀⠀⣰⡟⠂⠀⢿⡀⠀⠀⠀⠀⠀⠀⠈⠈⠀⠁⠀⠀⠀⠀⠀⣴⡟⠀⢀⡿⠀⠀⠀⠑⠉⠛⠲⠶⣤⣤⡀⠀⠀⠀⠀⠈⡗⠀⢾⡆⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀
⠈⠉⠉⠙⠛⠛⠒⠒⠒⠛⠒⠒⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠛⠲⣤⣀⠀⢸⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠹⣿⣶⣶⣤⣤⣄⣀⣀⡀⠀⠀⠀⠀⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠉⠻⠾⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠈⠙⠻⢿⣿⣿⣿⣿⣿⡇⠀⠀⠞⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⠤⠶⠖⠛⠛⠛⠛⠛⠳⠂⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠈⣹⣿⣿⣿⡇⠀⠀⠀⠿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡟⠀⠀⠀⠀⠀⠀⠀⠀⣀⠴⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣷⠀⠀⠀⠀⠻⣆⠀⠀⠀⠀⠀⠀⠀⣸⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⡾⠻⣯⡛⢷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⡀⠀⠀⠀⠀⠹⣧⠀⠀⠀⠀⠀⠀⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠋⠀⠀⠘⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣷⣄⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠘⢷⡀⠀⠀⠀⢰⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⠁⢀⣠⣶⡀⢹⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣿⣷⣄⣀⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠈⠻⣦⠀⠀⣾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⡿⢁⡴⠛⠁⠘⣧⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⡤⠤
⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠈⢳⣴⣏⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⢋⡴⠋⠀⠀⠀⠀⠘⡇⣿⠀⠀⠀⠀⠀⠸⣏⠉⠉⠀⠀⠀
⠀⢠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⡀⠀⠀⠀⠀⠀⠛⠉⠀⠀⠀⠀⠀⠀⡎⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣷⠟⠀⠀⠀⠀⠀⠀⠀⢻⣿⠀⠀⠀⠀⠀⠀⠈⠛⢦⡀⠀⠀
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⠦
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠛⢦⡀⠀⠀⠀⠀⠀⠀⠀⢀⡟⠀⠀⠀⠀⠀⠀⠀⠀⣼⡿⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠘⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣿⣿⣿⡟⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⠙⠢⠀⠀⠀⠀⠀⠀⢸⠇⠀⠀⠀⠀⠀⠀⠀⢸⡟⠀⠀⠀⣿⡟⢦⡀⠀⠀⠀⠀⢸⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣿⣿⣿⣿⡀⢸⣿⠉⠛⠿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⢠⡟⠀⠀⠀⠀⣿⣧⠀⢧⠀⠀⠀⠀⣸⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣿⣿⣿⣿⣷⡈⢿⡆⠀⠀⠈⠙⠻⢿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⣾⠃⠀⠀⠀⠀⢹⣿⣿⣿⣧⠀⠀⠀⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣿⣿⣿⣿⣿⣷⡘⣿⡄⠀⠀⠀⠀⠀⠉⠛⢿⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡆⠀⠀⠀⠀⠀⢸⡏⠀⠀⠀⠀⠀⠀⢿⣿⣾⣿⡀⠀⣸⣏⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠛⠿⠿⣿⣿⣿⣿⣿⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠷⣤⣀⠀⠀⠀⠀⠀⠀⠀⣁⠀⠀⠀⠀⢠⣿⠀⠀⠀⠀⠀⠀⠀⠘⣿⠿⢇⣧⡰⠟⠋⠉⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠈⠉⣹⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⠶⣤⣀⣀⠀⢀⣿⣧⡀⠀⢀⣿⢧⠀⠀⠀⠀⠀⠀⠀⠀⠘⣷⠞⠋⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢠⡴⠏⠀⠙⢿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⣿⡟⠛⠛⠶⠿⠋⠘⡄⠀⠀⠀⠀⠀⠀⣠⠞⠁⠀⠀⠀⠀⠀⢰⣷⣶⣶⣶⣶⣤⣤⣤⣤⣤⣤⣤
⠀⢀⣠⡾⠋⠀⠀⠁⣠⣶⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⡻⣿⣧⣀⣤⡤⠤⢤⡤⠵⠦⢤⣤⣀⢠⠞⠁⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⡾⠛⠁⠀⠀⣀⣴⣾⣿⠿⢿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣶⠿⠿⣿⣷⣶⣤⡿⠉⠀⠀⠀⠀⠀⠉⠁⠀⢀⣠⢶⣶⣶⡦⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⢀⣀⣤⣴⣿⣿⣿⡟⠁⠀⠀⠀⠉⠻⣿⣿⣿⣿⣦⣄⡀⠀⠀⠀⢀⣼⣿⣷⣤⣤⣾⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠋⢠⣾⣿⡿⢃⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⠿⠿⠿⠿⠥⣄⡐⠀⠀⠀⣠⣿⣿⣿⣿⡄⠈⠉⠛⠒⠒⠛⠁⠈⠙⠛⠛⠋⠉⠀⢧⡀⠀⠀⠀⠀⠀⢀⣴⣋⣤⣾⣿⡿⠋⣴⡿⠁⠈⠙⠻⣯⣙⠛⠛⠛⠋⠉⠉⠉⠉⠀
⣿⠏⠀⠀⠀⠤⣀⣠⣬⣽⣶⣶⣾⣿⣿⣿⣿⣿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠦⣤⢀⣠⣴⣿⣿⣿⡿⠛⠉⣠⣾⡿⢿⣶⣆⣀⡄⠈⠛⢷⣦⣄⠀⠀⠀⠀⠀⠀
⠏⠀⠀⠀⢀⡴⠋⠀⠲⢄⠀⠀⠙⠻⣿⣿⣿⣿⣿⣿⣷⣦⣀⡈⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠠⠼⠍⠉⠁⠐⠛⠋⢁⣠⡴⠚⠉⢀⡴⠟⠋⣽⡟⠁⠀⠀⠀⠙⠻⣿⣦⣀⠀⠀⠀
⠀⠀⠀⣠⠟⠁⠀⠀⠀⢀⡵⠶⠤⣀⡈⢻⣿⣿⣿⣿⣿⣿⡿⠿⠛⠶⠦⣄⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣤⣶⣶⠟⠁⠀⠠⠞⠁⠀⠀⣘⣿⠟⠛⢶⣄⠀⠀⠀⠈⠙⠻⣷⣄⠀
⠀⠀⠐⠁⠀⠀⠀⢀⡴⠋⠀⠀⠑⢄⠈⠛⢿⡟⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣞⣋⣉⡉⠀⠀⣨⠟⠁⠀⠀⠀⠀⠀⠀⣠⣾⣿⣼⠗⠀⠀⠙⢷⣄⡀⠀⠀⠀⠀⠙⠷
⠀⠀⠀⠀⠀⢀⡴⠋⠀⠀⠀⠀⠀⠈⣳⣀⡀⠙⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⡿⠚⠉⠉⠀⠀⢠⠋⠀⠀⠀⠀⠀⠀⠀⡜⣩⡽⠛⠁⠀⠀⠀⠀⢸⠻⣿⣦⣄⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⢀⣠⠞⠁⠘⢭⡒⢼⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢯⣷⣦⠀⠀⢰⡾⠀⠀⠀⠀⠀⠀⣠⣫⡿⠋⠀⠀⠀⠀⠀⠀⠀⢸⠀⠙⣿⣿⣷⣄⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠁⠀⠀⠀⠀⠙⠶⢳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢳⣄⢸⠀⠀⠀⠀⠀⠀⢀⣾⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠀⠀⠈⢿⣿⣿⣷⣄
⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠁⠀⠀⠀⠀⠀⡀⠀⠀⢸⣇⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣷⡇⡀⠀⠀⠀⣠⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡿⠀⠀⠀⠀⠻⣿⣿⣿
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠾⠖⠋⣰⠏⠀⠉⡳⣦⣤⡀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⡝⣦⣀⣀⣼⣟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⡇⢀⣀⡀⠀⠀⢻⣿⣿
*/
/*
Eu vim fazer um anúncio, Shadow o ouriço é um filha da puta do caralho,
ele mijou na porra da minha esposa,isso mesmo, ele pegou a porra do pinto
espinhoso dele e mijou na porra da minha esposa e disse que o pau dele era
dessa tamanho e eu disse "Credo, que nojo" então estou fazendo um exposed
no meu twitter.com. Shadow o ouriço, você tem um pau pequeno, que é do tamanho
desta noz só que muito menor, e adivinha, olha o tamanho do meu pirocão.
Isso mesmo bebê, pontas altas, sem pelos, sem espinhos, olha só, parecem
2 bolas e 1 torpedo. Ele fodeu a minha esposa, então adivinhem, eu vou foder
a terra, isso mesmo, isso que você ganha, meu super laser de mijo. Exceto que
eu não vou mijar na terra, eu vou mijar na lua, você gostou disto Lula, eu mijei
na lua, faz o L agora. vocês tem 23 horas antes que os meus perdigotos de mijo
atinjam a Terra. Agora saiam da porra da minha frente, antes que eu mije em vocês também
*/

//Indexado em 1
struct Centroid{
    int n;
    vector<int> used, pai, sub;
    vector<vector<int >> vec;
    
    vector<map<int,int>> brt;

    Centroid(int n) : n(n), used(n+1), pai(n+1), sub(n+1), vec(n+1), brt(n+1) {}

    void add_edge(int v, int u){
        vec[v].push_back(u);
        vec[u].push_back(v);
    }

    int dfs_sz(int x, int p=0){
        sub[x]=1;
        for(int i:vec[x]){
            if(i==p || used[i]) continue;
            sub[x]+=dfs_sz(i, x);
        }
        return sub[x];
    }

    int find_c(int x, int total, int p=0){
        for(int i:vec[x]){
            if(i==p || used[i]) continue;
            if(2*sub[i]>total) return find_c(i, total, x);
        }
        return x;
    }
    
    void build(int x=1, int p=0){
        int c=find_c(x, dfs_sz(x));

        //do something
        
        used[c]=1;
        pai[c]=p;
        for(int i:vec[c]){
            if(!used[i]) build(i, c);
        }
    }

    void solve(){

    }

};

struct LCA{
    
    int n;
    const int sz = 32;
    vector<int> marc, height;
    vector<vector<int>> g, bl, sm;

    LCA(int n) : n(n), g(n+1), bl(sz, vector<int> (n+1, 1)), marc(n+1), height(n+1), sm(sz, vector<int> (n+1, 0)){} //Rooted em 1

    void add_edge(int a, int b){
        g[a].push_back(b);
        g[b].push_back(a);
    }

    void build(int x = 1, vector<int> &pesos){ //Rooted em 1
        marc[x] = 1;
        for(int i = 1; i < sz; i++){
            bl[i][x] = bl[i-1][bl[i-1][x]];
            sm[i][x] = sm[i-1][x] + sm[i-1][bl[i-1][x]];
        }

        for(auto viz : g[x]){
            if(marc[viz]) continue;
            bl[0][viz] = x;
            sm[0][viz] = pesos[x];
            height[viz] = height[x]+1;
            build(viz, pesos);
        }
    }

    int find_price(int a, int b, vector<int> &pesos){
        if(height[a] < height[b]) swap(a,b);

        int ans = pesos[a] + pesos[b];

        int dif = height[a] - height[b];
        for(int i = 0; i < sz; i++){
            if((1<<i) & dif){
                ans += sm[i][a];
                a = bl[i][a];
            }
        }

        assert(height[a] == height[b]);
        if(a == b) return ans - pesos[a];

        for(int i = sz-1; i >=0; i--){
            if(bl[i][a] == bl[i][b]) continue;
            ans += sm[i][a];
            ans += sm[i][b];
            a = bl[i][a];
            b = bl[i][b];
        }
        
        assert(a != b);
        assert(bl[0][a] == bl[0][b]);
        ans += sm[0][a];
        ans += sm[0][b];
        return ans - pesos[bl[0][a]];
    }

};

int main(){

    cin.tie(0), ios_base::sync_with_stdio(false);   
    
    int n; cin >> n;

    Centroid centroid(n);
    LCA lca(n);

    vector<int> p(n+1);
    for(int i = 1; i <= n; i++){
        char k; cin >> k;
        if(k == ')') p[i] = -1;
        else p[i] = 1;
    }

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        centroid.add_edge(a, b);
        lca.add_edge(a, b);   
    }

    lca.build();
    centroid.build();
    


}