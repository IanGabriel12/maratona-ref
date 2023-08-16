// Grafo bipartido
// Colorir com 2 cores. Inicialize as cores com -1
void colorir(int r) {
  queue<int> q;
  q.push(r);
  color[r] = 0;
  while(!q.empty()) {
    auto x = q.front();
    q.pop();

    for(auto y : graph[x]) {
      if(color[y] == -1) {
        color[y] = !color[x];
        q.push(y);
      }
    }
  }
}

// Checar biparticao
bool check() {
  for(int i=1; i<=n; i++) {
    if(color[i] == -1) {
      colorir(i);
    }
  }
  
  for(int i=1; i<=n; i++) {
    for(auto y : graph[i]) {
      if(color[i] == color[y]) {
        return false;
      }
    }
  }

  return true;
}