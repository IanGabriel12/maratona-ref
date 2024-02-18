// Hash - 1 Base
const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7; // de pref. primo
const int P = 135; // um numero random maior que o tamanho do alfabeto
int p[MAX]; // p[i] == p^i % MOD
// lembre-se de rodar hsh_precalc
void hsh_precalc() {
    p[0] = 1;
    for(int i=1; i<MAX; i++) {
        p[i] = (p[i-1]*P) % MOD;
    }
}
struct StringHash {
    vector<int> hsh;
    StringHash(string _s) {
        // 1 - indexado
        hsh.resize(_s.size()+1);
        hsh[0] = 0;
        for(int i=1; i<=_s.size(); i++) {
            hsh[i] = ((hsh[i-1]*P)%MOD + _s[i-1])%MOD;
        }
    }
    // retorna hash de s[l...r] (1-indexado)
    int substr(int l, int r) {
        return (MOD + hsh[r] - (hsh[l-1]*p[r-l+1])%MOD) % MOD;
    }
};