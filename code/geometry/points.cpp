// Pontos (template)
struct pt {
  int x, y;
  pt(int x, int y) {
    this->x = x;
    this->y = y;
  }
  bool operator<(pt &r) {
    if(x == r.x) return y < r.y;
    return x < r.x;
  }
  bool operator==(pt &r) {
    return r.x == x && r.y == y;
  }
  pt operator-(pt &r) {
    return pt(x - r.x, y - r.y);
  }
};

// Produto escalar
int dot(pt a, pt b) {
  return a.x*b.x + a.y*b.y;
}

// Produto vetorial
int cross(pt a, pt b) {
  return a.x*b.y - a.y*b.x;
}

// angle BAC counter-clockwise
int orientation(pt a, pt b, pt c) {
  int v = cross(b - a, c - a);
  if (v < 0) return -1; // concavo
  if (v > 0) return +1; // convex
  return 0;
}

// Is the clockwise angle concavo?
bool cw(pt a, pt b, pt c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o < 0 || (include_collinear && o == 0);
}

// Is the counterclockwise angle convex? (<180)
bool ccw(pt a, pt b, pt c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o > 0 || (include_collinear && o == 0);
}

