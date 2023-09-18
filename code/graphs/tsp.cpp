// Caixeiro viajante
int ans[(1 << 20)][20];
bool calc[(1 << 20)][20];
int tsp(int set, int curr) {
  if(calc[set][curr]) return ans[set][curr];
  ll resp = LONG_LONG_MAX;
  for(pii &[weigh, neigh] : edg[curr]) {
    if(((set >> neigh) & 1) && neigh != curr) {
      resp = min(resp, weigh + tsp(set ^ (1ll << curr), neigh));
    }
  } 
  calc[set][curr] = true;
  return ans[set][curr] = resp;
}