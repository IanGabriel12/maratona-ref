// Longest Increasing Subsequence
// d[i] is the lowest last element of all 
// increasing sequences that have length i
int a[MAX];
int d[MAX];
int lis() {
  d[0] = MINUS_INF;
  for(int i=1; i<=n; i++) d[i] = INF;

  for(int i=0; i<n; i++) {
    int *pos = upper_bound(d, d+n+1, a[i]);
    // For it to be strictly increasing we need d[pos-1] < d[pos]
    if(*(pos - 1) < a[i] && a[i] < *pos) {
      *pos = a[i];
    }
  }

  for(int i=n; i>=1; i--) {
    if(d[i] != INF) {
      return i;
    }
  }
}
