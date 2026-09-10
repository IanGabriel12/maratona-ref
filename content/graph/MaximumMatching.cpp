/** 
 * Author: Ian Gabriel
 * Description: Matching máximo de um grafo bipartido. $n$ e $m$ são os tamanhos das partes. 
 * mt[i] é vértice da parte A que deu match com i (i é da parte B).
 * Time: $O(VE)$
 */
vector<int> g[MAXA];
bool used[MAXA];
int mt[MAXB], n, m;

bool findPath(int x) {
    if(used[x]) return false;
    used[x] = true;
    for(int y : g[x]) {
        if(mt[y] == -1 || findPath(mt[y])) {
            mt[y] = x;
            return true;
        }
    }
    return false;
}
int maximumMatching() {
    for(int i=0; i<m; i++) mt[i] = -1;
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int i=0; i<n; i++) used[i] = false;
        ans += findPath(i);
    }
    return ans;
}