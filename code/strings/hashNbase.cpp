// Hash - Múltiplas Bases
/**
 * lembre-se de setar QNTBASES corretamente
 * lembre-se de rodar hsh_precalc na primeira linha da main
 * p[i][j] eh bases[j]^i % mods[j]
 * substr(l, r) eh 1-indexado
*/
const int MAX = 1e6 + 10;
const int QNTBASES = 3;
vector<int> mods = {(int)1e9 + 7, 998244353, (int)1e9 + 9};
vector<int> bases = {135, 69, 318};

int p[MAX][QNTBASES]; 
void hsh_precalc() {
    for(int j=0; j<QNTBASES; j++) {
        p[0][j] = 1;
    }
    for(int i=1; i<MAX; i++) {
        for(int j=0; j<QNTBASES; j++) {
            p[i][j] = (p[i-1][j]*bases[j]) % mods[j];
        }
    }
}
struct MultiBaseStringHash {
    vector<vector<int>> hsh;
    MultiBaseStringHash(string _s) {
        hsh = vector<vector<int>>(_s.size()+1);
        for(int i=0; i<=_s.size(); i++) {
            hsh[i] = vector<int>(QNTBASES);
        }
        for(int j=0; j<QNTBASES; j++) {
            hsh[0][j] = 0;
        }
        for(int i=1; i<=_s.size(); i++) {
            for(int j=0; j<QNTBASES; j++) {
                hsh[i][j] = ((hsh[i-1][j]*bases[j])%mods[j] + _s[i-1]) % mods[j];
            }
        }
    }

    vector<int> substr(int l, int r) {
        vector<int> ans(QNTBASES);
        for(int j=0; j<QNTBASES; j++) {
            ans[j] = (mods[j] + hsh[r][j] - ((hsh[l-1][j]*p[r-l+1][j])%mods[j])) % mods[j];
        }
        return ans;
    }
};