// Encontrando centroide da árvore
// Finds the centroid of a tree in O(n)
// A centroid is a vertex where all of its subtrees have size <= n/2
int n;
vector<int> adj[MAX];
int sz[MAX]; //size of the subtree rooted at i

// pre-calculating the size of each subtree
int calc_sz(int x, int p) {
  for(auto y : adj[x]) {
    if(y != p) {
      sz[x] += calc_sz(y, x);
    }
  }
  sz[x]++;
  return sz[x];
}

int find_centroid(int x, int p) {
  for(auto y : adj[x]) {
    // If the subtree has size > n/2, the centroid is there
    if(y != p && sz[y] > n/2) {
      return find_centroid(y, x);
    }
  }
  return x;
}