// Li-Chao Tree

// Warning: não foi testada ainda
struct Line {
  ll a, b;
  Line(): a(0), b(-INF) {}
  Line(ll _a, ll _b): a(_a), b(_b) {} 
};

struct li_chao_tree {
  vector<Line> seg;
  int n;
  ll eval(Line l, int x) {
    return l.a*x + l.b;
  }

  li_chao_tree(int n) {
    this->n = n;
    seg.assign(4*n + 1);
  }

  void add_line(int id, int l, int r, Line line) {
    int m = (l+r)/2, e=2*id, d=2*id+1;
    if(eval(line, m) > eval(seg[id], m)) swap(line, seg[id]);
    if(eval(line, l) > eval(seg[id], l))
      add_line(e, l, m, line);
    if(eval(line, r) > eval(seg[id], r))
      add_line(d, m+1, r, line);
  }

  void add_line(ll a, ll b) {
    return add_line(1, 0, n, Line(a, b));
  }

  void add_segment(int id, int l, int r, Line line, int tl, int tr) {
    if(l > tr || r < tl) return;
    if(tl <= l && r <= tr) {
      add_line(id, l, r, line); return;
    }
    int m=(l+r)/2, e=2*id, d=2*id+1;
    add_segment(e, l, m, line, tl, tr);
    add_segment(d, m+1, r, line, tl, tr);
  }

  void add_segment(ll a, ll b, int tl, int tr) {
    return add_segment(1, 0, n, Line(a, b), tl, tr);
  }

  ll query(int id, int l, int r, int x) {
    if(l == r) return eval(seg[id], x);
    int m=(l+r)/2, e=2*id, d=2*id+1;
    ll ans;
    if(x <= m) ans = query(e, l, m, x);
    else ans = query(d, m+1, r, x);
    return max(eval(seg[id], x), ans);
  }

  ll query(int x) {
    return query(1, 0, n, x);
  }
};