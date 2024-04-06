    #include <bits/stdc++.h>
    using namespace std;
    #define endl "\n"
    #define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
    typedef long long ll;
    typedef unsigned long long ull;
    typedef pair<ll,ll> pii;
    typedef pair<ll,ll> pll;


    struct Edge{
        ll v, u;
        ll cap, flow = 0;
        Edge(ll v, ll u, ll cap) : v(v), u(u), cap(cap) {}
    };

    struct Dinic{
        ll INFL = 1e18;
        ll n, m = 0, s, t;
        vector<Edge> edges;
        vector<vector<ll>> vec;
        vector<ll> lv, pos;
        queue<ll> fila;

        Dinic(ll n, ll s, ll t): n(n), s(s), t(t), vec(n+1), lv(n+1), pos(n+1) {}

        void add_edge(ll v, ll u, ll cap){
            edges.emplace_back(v, u, cap);
            edges.emplace_back(u,v,0);
            vec[v].push_back(m);
            vec[u].push_back(m+1);
            m+=2;
        }

        ll bfs(){
            while (!fila.empty())
            {
                ll v = fila.front();
                fila.pop();
                for(ll i : vec[v]){
                    if(edges[i].cap - edges[i].flow < 1) continue;
                    if(lv[edges[i].u] != -1) continue;

                    lv[edges[i].u] = lv[v] + 1;
                    fila.push(edges[i].u);
                }
            }
            return lv[t] !=-1;
        }

        ll dfs(ll v, ll menor){
            if(!menor) return 0;
            if(v == t) return menor;

            for(ll& j=pos[v]; j < (ll)vec[v].size(); j++){
                ll i=vec[v][j];
                ll u=edges[i].u;

                if(lv[v]+1 != lv[u] || edges[i].cap - edges[i].flow < 1) continue;
                ll agr=dfs(u, min(menor, edges[i].cap - edges[i].flow));
                if(!agr) continue;

                edges[i].flow += agr;
                edges[i^1].flow -= agr;

                return agr;
            }
            return 0;
        }

        ll max_flow(){
            ll flow = 0;
            while (1)
            {
                fill(lv.begin(), lv.end(), -1);

                lv[s] = 0;
                fila.push(s);

                if(!bfs()) break;

                fill(pos.begin(), pos.end(), 0);

                while(ll atual=dfs(s,INFL)) flow += atual;
            }
            return flow;
        }

    };

    ll cont = 3;
    map<pll,ll> pr;
    map<ll, pll> rpr;
    map<ll, ll> res;
    map<ll,ll> Rres;


    ll MapPair(ll a, ll b){
        if(pr.count({a,b}) > 0){
        }else{
            pr[{a,b}] = cont;
            rpr[cont] = {a,b};
            cont++;
        }
        return pr[{a,b}];
    }

    ll MapInt(ll a){
        if(res.count(a) <= 0){
            res[a] = cont;
            Rres[cont] = a;
            cont++;
        }
        return res[a];
    }




    int main(){
        fastio;
        ll n; cin >> n;

        ll s = 1;
        ll t = 2;
        // [2...n+1] pares de números

        Dinic dinic(5 * n + 100, s, t);
        
        for(ll i = 2; i <= n+1; i++){
            ll a, b; cin >> a >> b; 
            
            dinic.add_edge(s, MapPair(a,b), 1);
            dinic.add_edge(MapPair(a,b), MapInt(a+b), 1);
            dinic.add_edge(MapPair(a,b), MapInt(a-b), 1);
            dinic.add_edge(MapPair(a,b), MapInt(a*b), 1);
        }

        for(auto a : res){
            ll i = a.first;
            dinic.add_edge(MapInt(i), t, 1);
        }

        int res = dinic.max_flow();

        if(res < n){
            cout << "impossible" << endl;
            return 0;
        }


        for(ll i=0; i<(ll)dinic.edges.size(); i+=2){
            if(dinic.edges[i].flow > 0 && dinic.edges[i].v != 1 && dinic.edges[i].v != 2 && dinic.edges[i].u != 1 && dinic.edges[i].u != 2){
                ll a = rpr[dinic.edges[i].v].first;
                ll b = rpr[dinic.edges[i].v].second;
                ll ans = Rres[dinic.edges[i].u];
                if(a + b == ans){
                    cout << a << " + " << b << " = " << ans  << endl;
                }else if( a * b == ans){
                    cout << a << " * " << b << " = " << ans  << endl;
                }else if(a - b == ans){
                    cout << a << " - " << b << " = " << ans  << endl;
                }
            }
        }




    }