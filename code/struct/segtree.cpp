// Segtree
/*
  Modificar os merges de acordo com o problema
*/

struct segtree {
  vector<ll> seg;
  int n;
  segtree(vector<ll> &v, int n) { // V esta 1-indexado
    this->n = n;
    seg.resize(4*n);
    build(1, 1, n, v);
  }

  void build(int id, int l, int r, vector<ll> &v) {
    if(l == r) {
      seg[id] = v[l];
      return;
    }
    int m = (l+r)/2, e=2*id, d=2*id+1;
    build(e, l, m, v);
    build(d, m+1, r, v);
    seg[id] = min(seg[e], seg[d]);
  }

  void update(int id, int l, int r, int pos, ll x) {
    if(l == r) {
      seg[id] = x;
      return;
    }
    int m = (l+r)/2, e = 2*id, d = 2*id+1;
    if(pos <= m) update(e, l, m, pos, x);
    else update(d, m+1, r, pos, x);
    seg[id] = min(seg[e], seg[d]);
  }

  void update(int pos, ll x) {
    update(1, 1, n, pos, x);
  }

  ll query(int id, int l, int r, int tl, int tr) {
    if(l > tr || tl > r) return numeric_limits<ll>::max();
    if(tl <= l && r <= tr) return seg[id];
    int m = (l+r)/2, e=2*id, d=2*id+1;
    return min(query(e, l, m, tl, tr), query(d, m+1, r, tl, tr));
  }

  ll query(int tl, int tr) {
    return query(1, 1, n, tl, tr);
  };
};