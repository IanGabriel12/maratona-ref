// Bridge-tree - Grafo simples
/*
    - Calcula a arvore de 2-edge-connected-components de um grafo.
    - Quaisquer 2 vertices em uma edge-biconnected-component tem
    pelo menos dois caminhos de um para o outro totalmente disjuntos em arestas.
    - As arestas da arvore sao as pontes do grafo original.
    - vtx[i] contem todos os vertices da componente i
    - Lembre-se de fazer edges.push_back({a, b}) quando ler a entrada;
    Complexidade: O(V + E)
*/
namespace bridgeTree {
    vector<int> g[MAX], tree[MAX], vtx[MAX];
    vector<pair<int, int>> edges;
    int pos[MAX], lo[MAX], marc[MAX], comp[MAX];
    int t, c;
    stack<int> s;

    void tarjan(int x, int p=-1) {
        pos[x] = t++;
        lo[x] = pos[x];
        marc[x] = 1;
        s.push(x);

        for(int y : g[x]) {
            if(!marc[y]) {
                tarjan(y, x);
                lo[x] = min(lo[x], lo[y]);
            } else {
                if(y == p) continue;
                lo[x] = min(lo[x], pos[y]);
            }
        }

        if(lo[x] == pos[x]) { // aresta x, p eh ponte
            int curr;
            c++;
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
            if(comp[x] != comp[y]) {
                tree[comp[x]].push_back(comp[y]);
                tree[comp[y]].push_back(comp[x]);
            }
        }
    }

    void build(int root=1) {
        c = 0;
        t = 0;
        tarjan(root);
        build_tree();
    }
}