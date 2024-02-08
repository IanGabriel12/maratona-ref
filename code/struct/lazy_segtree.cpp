// Segtree com lazy-propagation
struct lazy_segtree {
  vector<ll> seg, lazy;
  int n;
  lazy_segtree(vector<ll> &v, int n) { // v 1-indexado
    this->n = n;
    seg.resize(4*n + 10);
    lazy.resize(4*n + 10);
    build(1, 1, n, v);
  }
  void unlazy(int id, int l, int r) {
    if(lazy[id] == 0) return;
    ll num = lazy[id];
    lazy[id] = 0;
    seg[id] += (r-l+1)*num;
    if(l == r) return;
    int e=2*id, d=2*id+1;
    lazy[e] += num; lazy[d] += num;
  }
  void build(int id, int l, int r, vector<ll> &v) {
    if(l == r) {
      seg[id] = v[l];
      return;
    }
    int m=(l+r)/2, e=2*id, d=2*id+1;
    build(e, l, m, v);
    build(d, m+1, r, v);
    seg[id] = seg[e]+seg[d];
  }
  void update(int id, int l, int r, int tl, int tr, ll v) {
    if(l > tr || tl > r) return;
    if(tl <= l && r <= tr) {
      lazy[id] += v;
      return;
    }
    int m=(l+r)/2, e=2*id, d=2*id+1;
    update(e, l, m, tl, tr, v);
    update(d, m+1, r, tl, tr, v);
    unlazy(e, l, m);
    unlazy(d, m+1, r);
    seg[id] = seg[e]+seg[d];
  }
  void update(int tl, int tr, ll v) {
    return update(1, 1, n, tl, tr, v);
  }
  ll query(int id, int l, int r, int tl, int tr) {
    unlazy(id, l, r);
    if(l > tr || tl > r) return 0;
    if(tl <= l && r <= tr) return seg[id];
    int m=(l+r)/2, e=2*id, d=2*id+1;
    return query(e, l, m, tl, tr) + query(d, m+1, r, tl, tr);
  }
  ll query(int tl, int tr) {
    return query(1, 1, n, tl, tr);
  }

};