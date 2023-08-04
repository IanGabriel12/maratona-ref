// Componentes fortemente conexas
/* 1 - Realize uma DFS e armazene
 os vertices na ordem: ultimo a fechar -> primeiro a fechar
2 - Realize uma DFS no grafo transposto (invertido)
 na ordem do passo 1.
As SCC's serao encontradas no passo 2
*/
stack<int> order;
void dfs1(int x) {
  vis[x] = true;
  for(auto y : graph[x]) {
    if(!vis[y]) {
      dfs(y);
    }
  }
  order.push(x);
}

void dfs2(int x, vector<int> &scc_v) {
  vis[x] = true;
  scc_v.push_back(x);
  for(auto y : graph_t[x]) {
    if(!vis[y]) {
      dfs(y, scc_v);
    }
  }
}

void scc() {
  dfs1(1);
  memset(vis, 0, sizeof(vis));

  while(!order.empty()) {
    auto curr = order.top();
    order.pop();
    if(vis[curr]) continue;
    
    vector<int> scc_v;
    dfs2(curr, scc_v);
  }
}



