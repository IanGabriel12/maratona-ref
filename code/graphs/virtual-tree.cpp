// Virtual Tree
/**
 * Controi a arvore virtual dos vértices em O(k log k)
 * onde k é a quantidade de vértices considerados.
 * A árvore tem O(k) vértices.
 * Precisa de LCA, lembre de buildar o lca antes
*/
vector<int> virt[MAX];
int buildVirtual(vector<int> v) {
    auto comp = [&](int x, int y) {
        return lca::in[x] < lca::in[y]; 
    };
    sort(v.begin(), v.end(), comp);
    for(int i=v.size()-1; i; i--) {
        v.push_back(lca::lca(v[i], v[i-1]));
    }
    sort(v.begin(), v.end(), comp);
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=0; i<v.size(); i++) virt[v[i]].clear();
    vector<int> stc;
    stc.push_back(v[0]);
    for(int i=1; i<v.size(); i++) {
        while(stc.size() >= 2 && !lca::anc(stc.back(), v[i])) {
            virt[stc[stc.size() - 2]].push_back(stc.back());
            stc.pop_back();
        }
        stc.push_back(v[i]);
    }
    for(int i=0; i<stc.size()-1; i++) {
        virt[stc[i]].push_back(stc[i+1]);
    }
    return v[0];
}