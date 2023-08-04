// Bellman Ford
// Dentro da main
for(int i=1; i<=n; i++) dist[i] = INF;
dist[src] = 0;

for(int i=0; i<n-1; i++) {
  for(int u=1; u<=n; u++) {
    if(dist[u] == INF) continue;
    for(auto &[v, w] : graph[u]) {
      dist[v] = min(dist[v], dist[u] + w);
    }
  }
}