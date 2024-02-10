// LCA com HLD
// O(log n)
vector<int> g[MAX];
int pos[MAX], pai[MAX], sz[MAX];
int h[MAX];
int t;
void dfs(int x, int p=-1) {
    sz[x] = 1;
    for(int &y : g[x]) if(y != p) {
        dfs(y, x);
        sz[x] += sz[y];
        if(sz[y] > sz[g[x][0]]) swap(y, g[x][0]);
    }
}
void build_hld(int x, int p=-1) {
    pos[x] = t++;
    for(int y : g[x]) if(y != p) {
        pai[y] = x;
        h[y] = (y == g[x][0] ? h[x] : y);
        build_hld(y, x);
    }
}
void build(int root=1) {
    dfs(root);
    t = 0;
    h[root] = root;
    build_hld(root);
}
int lca(int a, int b) {
    if(pos[a] < pos[b]) swap(a, b);
    return h[b] == h[a] ? b : lca(pai[h[a]], b);
}