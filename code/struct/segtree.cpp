// Segtree
/*
    Segtree recursiva com lazy propagation
    Complexidades:
        query - log n
        update - log n
        build - n
*/

namespace segtree {
    int seg[4*MAX], lazy[4*MAX];
    int n, *v;
    
    void build(int id, int l, int r) {
        lazy[id] = 0;
        if(l == r) { seg[id] = v[l]; return; }
        int m=(l+r)/2, e=2*id, d=2*id+1;
        build(e, l, m); build(d, m+1, r);
        seg[id] = seg[e] + seg[d];
    }
    void build(int n2, int *v2) {
        n = n2, v = v2;
        build(1, 0, n-1); // cuidado com a indexacao!!!
    }
    void unlazy(int id, int l, int r) {
        seg[id] += (r-l+1)*lazy[id];
        if(l != r) lazy[2*id] += lazy[id], lazy[2*id+1] += lazy[id];
        lazy[id] = 0;
    }
    int query(int id, int l, int r, int tl, int tr) {
        unlazy(id, l, r);
        if(l > tr || tl > r) return 0;
        if(tl <= l && r <= tr) return seg[id];
        int m=(l+r)/2, e=2*id, d=2*id+1;
        return query(e, l, m, tl, tr) + query(d, m+1, r, tl, tr);
    }
    int query(int tl, int tr) {
        return query(1, 0, n-1, tl, tr); // aqui tambem
    }
    void update(int id, int l, int r, int tl, int tr, int v) {
        unlazy(id, l, r);
        if(l > tr || tl > r) return;
        if(tl <= l && r <= tr) { 
            lazy[id] += v;
            unlazy(id, l, r);
            return;
        }
        int m=(l+r)/2, e=2*id, d=2*id+1;
        update(e, l, m, tl, tr, v); update(d, m+1, r, tl ,tr, v);
        seg[id] = seg[e] + seg[d];
    }
    void update(int pos, int v) {
        return update(1, 0, n-1, pos, pos, v); // aqui
    }
    void update(int tl, int tr, int v) {
        return update(1, 0, n-1, tl, tr, v); // e aqui!!!
    }
};