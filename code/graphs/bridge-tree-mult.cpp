// Bridge-tree - Múltiplas arestas
/*
    e[x] sao os indices das arestas de x
    {
        ...
        e[a].push_back(i); e[b].push_back(i);
        edges.push_back({a, b});
        ...
    }
*/
namespace bridgeTree {
    vector<int> g[MAX], e[MAX];
    vector<int> tree[MAX], vtx[MAX];
    vector<pair<int, int>> edges;
    int marc[MAX], marcAresta[MAX];
    int pos[MAX], lo[MAX], comp[MAX];
    stack<int> s;
    int t, c;

    void tarjan(int x, int p=-1) {
        pos[x] = t++;
        lo[x] = pos[x];
        marc[x] = 1;
        s.push(x);
        for(int i=0; i<g[x].size(); i++) {
            int y = g[x][i];
            int idAresta = e[x][i];
            if(marcAresta[idAresta]) continue;
            marcAresta[idAresta] = true;
            if(!marc[y]) {
                tarjan(y, x);
                lo[x] = min(lo[x], lo[y]);
            } else {
                lo[x] = min(lo[x], pos[y]);
            }
        }

        if(lo[x] == pos[x]) {
            c++;
            int curr;
            do {
                curr = s.top();
                s.pop();
                comp[curr] = c;
                vtx[c].push_back(curr);
            } while(curr != x);
        }
    }

    void build_tree() {
        for(int i=0; i<edges.size(); i++) {
            auto [x, y] = edges[i];
            if(comp[y] != comp[x]) {
                tree[comp[y]].push_back(comp[x]);
                tree[comp[x]].push_back(comp[y]);
            }
        }
    }

    void build(int n) {
        t = 0;
        c = 0;
        for(int i=1; i<=n; i++) { // cuidado com a indexacao
            if(!marc[i]) tarjan(i);
        }
        build_tree();
    }
}