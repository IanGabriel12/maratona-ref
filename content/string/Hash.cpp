/**
 * Author: Ian Gabriel
 * Description: calc\_hash calcula o array de hash da string v. my\_hash calcula o hash da string no intervalo $[l, r]$
 * 0-indexado. p[i] é $B1^i$ módulo MOD.
 * Time: calc\_hash $O(|S|)$. my\_hash $O(1)$
 */
const int MOD = 1e9 + 7;
const int B1 = 9375;
int p[MAX];
vi calc_hash(string &v) { 
    vi h(v.size());
    h[0] = v[0]; p[0] = 1;
    for(int i=1; i<v.size(); i++) {
        p[i] = p[i-1]*B1%MOD; h[i] = (h[i-1]*B1 + v[i])%MOD;
    }
    return h;
}
 
int my_hash(vi &h, int l, int r) {
    int hash = h[r] - (l ? h[l-1]*p[r-l+1]%MOD : 0);
    return hash < 0 ? hash + MOD : hash;
}