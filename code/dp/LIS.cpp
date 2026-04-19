/*
  longest increasing subsequence - O(n log(n))
  d[i] = menor valor do final de uma subsequência de tamanho i
  resposta = maior i tal que d[i] != INF
*/
void lis(vi &a) {
  int n = a.size();
  vi d(n+1, INF);
  d[0] = -INF;

  rep(i, 0, n) {
    auto pos = upper_bound(all(d), a[i]);
    if(*prev(pos) < a[i]) {
      *pos = a[i];
    }
  }

  for(int i=n; i>=1; i--) if(d[i] != INF) {
    cout << i; break;
  }
}
