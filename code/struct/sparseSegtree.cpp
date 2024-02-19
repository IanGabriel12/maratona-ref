// Segtree Esparsa / Dinâmica
/**
 * Uma segtree normal mas que cria os nos conforme necessario
 * e[i] - indice do no esquerdo do i
 * d[i] - indice do no direito do i
 * na pos 0 esta o noh nulo e na pos 1 eh a raiz da seg
 * 
 * MAX deve ser Q * log N onde N eh o tamanho do intervalo e Q eh a 
 * quantidade de queries.
 * Este exemplo eh uma seg de soma com lazy propagation.
 * As complexidades sao as mesmas.
*/
namespace dynamic_seg {
    int soma[MAX], e[MAX], d[MAX], lazy[MAX];
    int ini, fim, ptr;
    void build(int _l, int _r) {
        ini = _l; fim = _r;
        ptr = 2;
    }
    int getEsq(int id) {
        if(e[id] == 0) e[id] = ptr++;
        return e[id];
    }
    int getDir(int id) {
        if(d[id] == 0) d[id] = ptr++;
        return d[id];
    }
    void refresh(int id, int l, int r) {
        soma[id] += (r - l + 1) * lazy[id];
        if(l != r) {
            lazy[getEsq(id)] += lazy[id];
            lazy[getDir(id)] += lazy[id];
        }
        lazy[id] = 0;
    }
    void update(int id, int l, int r, int tl, int tr, int value) {
        refresh(id, l, r);
        if(l > tr || tl > r) return;
        if(tl <= l && r <= tr) {
            lazy[id] += value;
            refresh(id, l, r);
            return;
        }
        int m=(l+r) >> 1;
        update(getEsq(id), l, m, tl, tr, value);
        update(getDir(id), m+1, r, tl, tr, value);
        soma[id] = soma[getEsq(id)] + soma[getDir(id)];
    }
    void update(int tl, int tr, int value) {
        return update(1, ini, fim, tl, tr, value);
    }
    int query(int id, int l, int r, int tl, int tr) {
        refresh(id, l, r);
        if(l > tr || tl > r) return 0;
        if(id == 0) return 0;
        if(tl <= l && r <= tr) return soma[id];
        int m=(l+r)>>1;
        return query(getEsq(id), l, m, tl, tr) + query(getDir(id), m+1, r, tl, tr);
    }
    int query(int tl, int tr) {
        return query(1, ini, fim, tl, tr);
    }
}