// MST - Kruskal
struct Edge {
  int w, u, v;
};

vector<Edge> edgs;
void kruskal() {
  // ordena pelo peso
  sort(edgs.begin(), edgs.end());
  vector<Edge> ans; // Resposta final
  for(int i=0; i<edgs.size(); i++) {
    Edge curr = edgs[i];
    // Usando DSU
    if(find(curr.u) == find(curr.v)) continue;
    ans.push_back(curr);
    join(curr.u, curr.v);
  }
}