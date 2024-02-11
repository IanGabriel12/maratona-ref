// HLD - Arestas

/*
    Precisa de Segtree
    Complexidades:
        build - n
        update (path) - log^2(n)
        update (point) - log(n)
        query - log^2(n)
        update_subtree - log n
        query_subtree - log n
    
    namespace segtree { ... }
*/ 
namespace hld {
    vector<pair<int, int>> g[MAX]; // {peso, vertice}
    int pos[MAX], v[MAX], pai[MAX], sobe[MAX], sz[MAX];
    int h[MAX];
    int t;

    void dfs(int x, int p=-1) {
        sz[x] = 1;
        for(auto &e : g[x]) if(e.second != p) {
            auto [w, y] = e;
            dfs(y, x);
            sz[x] += sz[y];
            if(sz[y] > sz[g[x][0].second] or g[x][0].second == p) swap(e, g[x][0]);
        }
    }
    void build_hld(int x, int p=-1) {
        pos[x] = t++;
        v[pos[x]] = sobe[x];
        for(auto &e : g[x]) if(e.second != p) {
            auto [w, y] = e;
            pai[y] = x;
            sobe[y] = w;
            h[y] = (y == g[x][0].second ? h[x] : y);
            build_hld(y, x);
        }
    }
    void build(int root=1) {
        dfs(root);
        t=0;
        h[root] = root;
        build_hld(root);
        segtree::build(t, v);
    }
    void update(int a, int v) { 
        // a eh o vertice mais abaixo da aresta
        segtree::update(pos[a], v);
    }
    int query(int a, int b) {
        if(pos[a] < pos[b]) swap(a, b);
        if(h[a] == h[b]) return segtree::query(pos[b]+1, pos[a]);
        return max(segtree::query(pos[h[a]], pos[a]), query(pai[h[a]], b));
    }
    void update_path(int a, int b, int v) {
        if(pos[a] < pos[b]) swap(a, b);
        if(h[a] == h[b]) return segtree::update(pos[b]+1, pos[a], v);
        segtree::update(pos[h[a]], pos[a], v);
        return update_path(pai[h[a]], b, v);
    }
    void update_subtree(int a, int v) {
        segtree::update(pos[a]+1, pos[a] + sz[a] - 1, v);
    }
    int query_subtree(int a) {
        return segtree::query(pos[a]+1, pos[a] + sz[a] - 1);
    }
}