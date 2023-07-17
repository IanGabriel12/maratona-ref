// Djikstra
void bfs(int root) {
  for(int i=1; i<MAX; i++) dist[i] = LONG_LONG_MAX;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, root});

  while(!q.empty()) {
    auto curr = q.top();
    auto d = curr.first;
    auto v = curr.second;
    q.pop();
    if(visited[v]) continue;
    visited[v] = true;
    dist[v] = d;

    for(auto p : adj[v]) {
      auto du = p.first;
      auto u = p.second;
      if(!visited[u] && dist[v] + du < dist[u]) {
        q.push({dist[v] + du, u});
      }
    }
  }
}