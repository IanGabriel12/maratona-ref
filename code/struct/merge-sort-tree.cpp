// Merge Sort Tree
/*
    Segtree sem update onde cada no contem o vetor
    do intervalo ordenado

    Complexidade: 
        build - n
        query - log^2 n para este problema
    Memoria: n log n
*/
struct Node {
    vector<int> elel;
    Node(vector<int> v): elel(v) {};
};

namespace mergeTree {
    Node seg[4*MAX];
    int n, *v;
    vector<int> merge_vector(vector<int> &a, vector<int> &b) {
        int sz = a.size() + b.size();
        vector<int> res(sz);
        int i=0, j=0, pos=0;
        while(i < (int)a.size() && j < (int)b.size()) {
            if(a[i] < b[j]) res[pos++] = a[i++];
            else res[pos++] = b[j++];
        }
        if(j == (int)b.size()) 
            for(int k=i; k<(int)a.size(); k++) res[pos++] = a[k];
        else
            for(int k=j; k<(int)b.size(); k++) res[pos++] = b[k];
        
        return res;
    }

    Node merge(Node &a, Node &b) {
        return Node(merge_vector(a.elel, b.elel));
    }

    void build(int id, int l, int r) {
        if(l == r) {
            seg[id] = Node({v[l]});
            return;
        }
        int m=(l+r)/2, e=2*id, d=2*id+1;
        build(e, l, m); build(d, m+1, r);
        seg[id] = merge(seg[e], seg[d]);
    }

    int query(int id, int l, int r, int tl, int tr, int x) {
        if(tl > r || l > tr) return 0;
        if(tl <= l && r <= tr) {
            auto ptr = upper_bound(seg[id].elel.begin(), seg[id].elel.end(), x);
            int idx = ptr - seg[id].elel.begin();
            return idx;
        }
        int m=(l+r)/2, e=2*id, d=2*id+1;
        return query(e, l, m, tl, tr, x) + query(d, m+1, r, tl, tr, x);
    }

    void build(int n2, int *v2) {
        n = n2; v = v2;
        build(1, 0, n-1); // cuidado com a indexacao
    }

    int query(int tl, int tr, int x) {
        return query(1, 0, n-1, tl, tr, x); // aqui tambem
    }

}