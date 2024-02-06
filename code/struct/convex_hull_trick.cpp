// Convex Hull Trick - Estático
/*
  As retas devem ser inseridas por ordem de coeficiente
  angular (desempate pelo coeficiente linear).
  A maior reta deve ser inserida atras. A menor reta deve
  ser inserida na frente.

  query(x) - Retorna o maior valor entre todas as retas no ponto x
  add_line_back(a, b) - Adiciona a reta ax + b no final da estrutura
  add_line_front(a, b) - Adiciona a reta ax + b no comeco da estrutura

  Complexidades:
    query - O(log n)
    add_line_back - O(1) amortizado
    add_line_front - O(1) amortizado
*/

struct Line {
  ll a, b, x_inter;
  bool operator<(ll x) const {
    return x_inter < x;
  }
};

struct cht {
  deque<Line> hull;

  ll intersection(Line x, Line y) {
    assert(x.a != y.a);
    return (x.b - y.b) / (y.a - x.a);
  }

  void add_line_back(ll a, ll b) {
    if(!hull.empty() && hull.back().a == a) hull.pop_back();
    while(hull.size() >= 2) {
      auto x = hull[hull.size() - 2];
      auto y = hull[hull.size() - 1];
      if(intersection(y, {a, b, 0}) < intersection(x, y)) {
        hull.pop_back();
      } else break;
    }

    if(!hull.empty()) 
      hull.back().x_inter = intersection(hull.back(), {a, b, 0});

    const ll INF = numeric_limits<ll>::max();
    hull.push_back({a, b, INF});
  }

  ll query(ll x) {
    int j =  lower_bound(hull.begin(), hull.end(), x) - hull.begin();
    return hull[j].a*x + hull[j].b;
  }

  void add_line_front(ll a, ll b) {
    if(!hull.empty() && hull[0].a == a) return;
    while(hull.size() >= 2) {
      auto x = hull[0];
      auto y = hull[1];

      if(intersection(x, {a, b, 0}) > intersection(x, y)) {
        hull.pop_front();
      } else break;
    }

    const ll INF = numeric_limits<ll>::max();
    hull.push_front({a, b, INF});
    if(hull.size() > 1)
      hull[0].x_inter = intersection(hull[0], hull[1]);

  }

  
};