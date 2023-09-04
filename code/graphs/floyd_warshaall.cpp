
// Floyd-Warshall O(n^3)
// (all shortest paths between nodes in single run)
void floyd_warshall() {
  for (int k=1; k<=n; k++) {
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=n; j++) {
        distance[i][j] = min(distance[i][j],
          distance[i][k]+distance[k][j]);
      }
    }
  }
}
