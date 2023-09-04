// Diâmetro de árvore
// Finds the diameter of a tree in O(n)
// The diameter is the maximum distance between two nodes

int find_diameter() {
  dfs(1, -1);
  int u = -1;
  int max_dist = -1;
  // Find the most distant vertex u from root
  for(int i=1; i<=n; i++) {
    if(dist[i] > max_dist) {
      u = i;
      max_dist = dist[i];
    }
  }

  memset(dist, 0, sizeof(dist));
  dfs(u, -1);
  
  // Find the most distant vertex from u
  int v = -1;
  max_dist = -1;
  for(int i=1; i<=n; i++) {
    if(dist[i] > max_dist) {
      v = i;
      max_dist = dist[i];
    }
  }

  return max_dist;
}