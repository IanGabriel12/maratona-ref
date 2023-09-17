// Smallest enclosing circle in O(n)
#define double long double

struct Point {
  double x,y;
};
struct Circle {
  Point c;
  double r;
};

double dist(Point a, Point b) {
  return hypot(a.x-b.x, a.y-b.y);
}
bool is_inside(Circle c, Point p) {
  return dist(c.c, p) <= c.r;
}

//minimal circle from 3 points
Circle circle_from(Point a, Point b, Point c) {
  double bx = b.x - a.x;
  double by = b.y - a.y;
  double cx = c.x - a.x;
  double cy = c.y - a.y;

  double bv = bx*bx + by*by;
  double cv = cx*cx + cy*cy;
  double d = bx*cy - by*cx;

  Point center = {
    (cy * bv - by * cv) / (2 * d),
    (bx * cv - cx * bv) / (2 * d)
  };
  center.x += a.x;
  center.y += a.y;

  return { center, dist(center, a) };
}
// minimal circle from 2 points
Circle circle_from(Point a, Point b) {
  Point c = {
    (a.x + b.x) / 2.0,
    (a.y + b.y) / 2.0
  };
  return { c , dist(a,b) / 2.0 };
}

bool is_valid_circle(Circle c, vector<Point> ps) {
  for (auto p: ps) {
    if (!is_inside(c,p)) return false;
  }
  return true;
}

Circle min_circle_trivial(vector<Point> ps)
{
  if (ps.empty()) return { { 0, 0 }, 0 };
  else if (ps.size() == 1) return { ps[0], 0 };
  else if (ps.size() == 2) return circle_from(ps[0], ps[1]);

  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      Circle c = circle_from(ps[i], ps[j]);
      if (is_valid_circle(c, ps)) return c;
    }
  }
  return circle_from(ps[0], ps[1], ps[2]);
}

Circle welzl_helper(vector<Point> ps, vector<Point> rs, int n)
{
  if (n == 0 || rs.size() == 3) {
      return min_circle_trivial(rs);
  }
  int rand_i = rand() % n;
  Point p = ps[rand_i];
  swap(ps[rand_i], ps[n - 1]);

  Circle d = welzl_helper(ps, rs, n - 1);

  if (is_inside(d, p)) return d;

  rs.push_back(p);

  return welzl_helper(ps, rs, n - 1);
}
// minimal enclosing circle
Circle welzl(vector<Point> ps)
{
    vector<Point> pscopy = ps;
    random_shuffle(pscopy.begin(), pscopy.end());
    return welzl_helper(pscopy, {}, pscopy.size());
}
