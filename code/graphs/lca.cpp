// LCA - Binary lifting
vector<int> graph[MAX];
int level[MAX];
int pai[MAX];
int anc[MAX][MAXL];
int n, q;

void dfs(int u, int p) {
  for(auto x : graph[u]) {
    if(x != p) {
      pai[x] = u;
      level[x] = level[u] + 1;
      dfs(x, u);
    }
  }
}

void calc_anc() {
  for(int i=1; i<=n; i++) {
    for(int j=0; j<MAXL; j++) {
      anc[i][j] = -1;
    }
  }

  for(int i=1; i<=n; i++) {
    anc[i][0] = pai[i];
  }

  for(int j=1; j<MAXL; j++) {
    for(int i=1; i<=n; i++) {
      anc[i][j] = anc[anc[i][j-1]][j-1];
    }
  }
}

int lca(int u, int v) {
  // v esta sempre acima
  if(level[u] < level[v]) swap(u, v);

  for(int i=MAXL-1; i>=0; i--) {
    if(level[u] - (1 << i) >= level[v]) {
      u = anc[u][i];
    }
  }

  if(u == v) return u;

  for(int i=MAXL-1; i>=0; i--) {
    if(anc[u][i] != -1 && anc[u][i] != anc[v][i]) {
      u = anc[u][i];
      v = anc[v][i];
    }
  }

  return pai[u];
}