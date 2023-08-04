// Ordenação topológica
// Processe os vertices com grau de entrada 0
while(!q.empty()) {
  auto curr = q.front();
  q.pop();
  for(auto viz : graph[curr]) {
    deg[viz]--;
    if(deg[viz] == 0) {
      q.push(viz);
    }
  }
}

