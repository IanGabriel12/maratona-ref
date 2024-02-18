// Hash - Não ordenado
/**
 * Hash de multiconjunto. A ordem dos elementos nao importa,
 * apenas a quantidade de cada um. Ex: AAB == ABA mas BBA != BAA
 * Lembre-se de rodar hsh_precalc na primeira linha da main.
 * Precisa de exponenciacao rapida e inversos modulares, 
 * por isso MOD precisa ser um primo grande.
 * substr(l, r) eh 1 indexado.
 * Warning: Nao foi testado ainda.
*/
const int MAX = 1e5 + 10;
const int MOD = 1e9 + 7;
const int P = 125;

int p[MAX];
void hsh_precalc() {
    p[0] = 1;
    for(int i=1; i<MAX; i++) {
        p[i] = (p[i-1]*P)%MOD;
    }
}

struct UnorderedHash {
    vector<int> hsh;
    UnorderedHash(string _s) {
        hsh.resize(_s.size()+1, 1);
        hsh[0] = 1;
        for(int i=1; i<=_s.size(); i++) {
            hsh[i] = (hsh[i-1]*(_s[i-1]+P))%MOD;
        }
    }
    int substr(int l, int r) {
        return (hsh[r]*modInv(hsh[l-1]))%MOD;
    }
};