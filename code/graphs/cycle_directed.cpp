// Encontrar ciclo (Direcionado)
// try to find a vertex that is visited but not closed
/* color[x]
0 - Not visited
1 - Visited but not closed
2 - Visited and closed
*/
bool dfs(int x) {
  color[x] = 1;
  for(int u : adj[x]) {
    if(color[u] == 1) {
      cycle_start = u;
      cycle_end = x;
      return true;
    } else if (color[u] == 0) {
      parent[u] = x;
      if(dfs(u)) return true;
    }
  }

  color[x] = 2;
  return false;
}

void find_cycle() {
  ...
  for(int i=1; i<=n; i++) {
    if(color[i] == 0 && dfs(i)) break;
  }
  ...
  // DON'T' forget to reverse the cycle
    reverse(cycle.begin(), cycle.end());
}