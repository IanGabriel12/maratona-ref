// HLD - Vértices
/*
    precisa de segtree
    Complexidades:
        build - n
        update (path) - log^2(n)
        update (point) - log(n)
        query - log^2(n)
        update_subtree - log n
        query_subtree - log n
*/ 

namespace hld {
    vector<int> g[MAX];
    int pos[MAX], pai[MAX], v[MAX], sz[MAX], val[MAX];
    int h[MAX];
    int t;

    void dfs(int x, int p=-1) {
        sz[x] = 1;
        for(int &y : g[x]) if(y != p) {
            dfs(y, x);
            sz[x] += sz[y];
            if(sz[y] > sz[g[x][0]] or g[x][0] == p) swap(y, g[x][0]);
        }
    }
    void build_hld(int x, int p=-1) {
        pos[x]=t++;
        v[pos[x]] = val[x];
        for(int &y : g[x]) if(y != p) {
            h[y] = (y == g[x][0] ? h[x] : y);
            pai[y] = x;
            build_hld(y, x);
        }
    }
    void build(int n, int root=1) {
        dfs(root);
        t=0;
        h[root] = root;
        build_hld(root);
        segtree::build(t, v);
    }
    void update(int a, int b, int v) {
        if(pos[a] < pos[b]) swap(a, b);
        if(h[a] == h[b]) return segtree::update(pos[b], pos[a], v);
        segtree::update(pos[h[a]], pos[a], v);
        update(pai[h[a]], b, v);
    }
    int query(int a, int b) {
        if(pos[a] < pos[b]) swap(a, b);
        if(h[a] == h[b]) return segtree::query(pos[b], pos[a]);
        return segtree::query(pos[h[a]], pos[a]) + query(pai[h[a]], b);
    }
    // nao testado
    int query_subtree(int a) {
        return segtree::query(pos[a], pos[a] + sz[a] - 1);
    }
    void update_subtree(int a, int v) {
        return segtree::update(pos[a], pos[a] + sz[a] - 1, v);
    }
    void update(int a, int v) {
        return segtree::update(pos[a], v);
    }
};