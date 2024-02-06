// Convex Hull Trick - Dinâmico
/*
  As retas podem ser inseridas em qualquer ordem.

  query(x) - Retorna o maior valor que x pode assumir entre
  todas as retas
  add_line(a, b) - Adiciona a reta ax + b na estrutura
  Complexidades:
    query(x) - O(log n)
    add_line(a, b) - O(log n) amortizado
*/

struct Line {
  ll a, b;
  mutable ll x_inter;
  bool operator<(const Line &l) const {
    return make_pair(a, b) < make_pair(l.a, l.b);
  }
  bool operator<(const ll x) const {
    return x_inter < x;
  }
};

struct dynamic_hull : multiset<Line, less<>> {
  void fix_x_inter(iterator it) {
    if(next(it) != end()) {
      it->x_inter = (next(it)->b - it->b) / (it->a - next(it)->a);
    }
  }

  ll intersection(Line x, Line y) {
    assert(x.a != y.a);
    return (x.b - y.b) / (y.a - x.a);
  }

  void add_line(ll a, ll b) {
    const ll inf = numeric_limits<ll>::max();
    auto it = insert({a, b, inf});
    if(next(it) != end() && next(it)->a == a) {
      erase(it);
      return;
    }
    if(prev(it) != begin() && prev(it)->a == a) {
      erase(prev(it));
      if(it != begin()) fix_x_inter(prev(it));
    }
    if(it != begin() && next(it) != end()) {
      if(intersection(*it, *prev(it)) >= intersection(*it, *next(it))) {
        erase(it);
        return;
      }
    }
    while(it != begin() && prev(it) != begin()) {
      auto y = prev(it);
      auto x = prev(y);
      if(intersection(*x, *it) <= intersection(*x, *y)) {
        erase(y);
      } else break;
    }
    while(next(it) != end() && next(next(it)) != end()) {
      auto x = next(it);
      auto y = next(x);
      if(intersection(*x, *it) > intersection(*x, *y)) {
        erase(x);
      } else break;
    }

    fix_x_inter(it);
    if(it != begin()) fix_x_inter(prev(it));
  }

  ll query(ll x) {
    auto l = *lower_bound(x);
    return l.a*x + l.b;
  }
};