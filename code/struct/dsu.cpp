// DSU
// Inicialmente pai[i] = i
int pai[MAX];
int depth[MAX];

int find(int x) {
  if(pai[x] == x) return x;
  return pai[x] = find(pai[x]);
}

void join(int x, int y) {
  int px = find(x);
  int py = find(y);
  if(px == py) return;

  if(depth[py] > depth[px]) {
    pai[px] = py;
  } else if (depth[py] < depth[px]) {
    pai[py] = px;
  } else {
    pai[px] = py;
    depth[py]++;
  }

  return;
}