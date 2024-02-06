// Longest Increasing Subsequence

/*
d[i] eh o menor elemento final de todas 
as subsequencias de tamanho i
*/
const int INF = 1e9;
const int MAX = 2e5;

int n;
int a[MAX];
int d[MAX];
int lis() {
  d[0] = -INF;
  for(int i=1; i<=n; i++) d[i] = INF;

  for(int i=0; i<n; i++) {
    int *pos = upper_bound(d, d+n+1, a[i]);
    // para ser estritamente crescente precisamos d[pos-1] < d[pos]
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
