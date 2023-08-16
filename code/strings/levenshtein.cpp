// Edit distance
int dist[MAX][MAX];
string s, t;

int lev(int n, int m) {
  // Lembre de inicializar
  if(dist[n][m] != -1) return dist[n][m];
  if(n == 0) return dist[n][m] = m;
  if(m == 0) return dist[n][m] = n;
  dist[n][m] = min({
    (s[n-1] != t[m-1]) + lev(n-1, m-1),
    1 + lev(n, m-1),
    1 + lev(n-1, m)
  });

  return dist[n][m];
}