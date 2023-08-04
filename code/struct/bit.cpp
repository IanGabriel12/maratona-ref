// Fenwick tree
int arr[MAX]; // O array original
int fenw[MAX]; // Fenwick tree
int n;

int prefix(int x) {
  int sum = 0;
  while(x > 0) {
    sum += fenw[x];
    x -= (x & -x);
  }
  return sum;
}

int range(int x, int y) { // (x, y]
  return prefix(y) - prefix(x); 
}

void update(int idx, int value) {
  while(idx <= n) {
    fenw[idx] += value;
    idx += (idx & -idx);
  }
}

void build() {
  for(int i=1; i<=n; i++) {
    fenw[i] += arr[i];
    if(i + (i & -i) <= n) {
      fenw[i + (i & -i)] += fenw[i];
    }
  }
}