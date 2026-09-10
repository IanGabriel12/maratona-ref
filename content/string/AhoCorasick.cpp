/**
 * Author: Ian Gabriel
 * Description: Autômato de Aho-Corasick. lnk[i] é o suffix link de i. go[i][j] é o automato.
 * ex[i] é o proximo vertice terminal seguindo pelos links de i, e nmatches[i] é a quantidade de matches
 * do estado i.
 * Time: Inserção $O(|S|)$. Build $O(\sum{|S_i|}k)$
 * Usage: start no começo, adiciona as strings, depois rode o build
 * Details: MAX é o máximo de vértices na trie, K é o tamanho do alfabeto
 */
namespace Aho {
    int lnk[MAX], go[MAX][K], ex[MAX], nmatches[MAX];
    bool output[MAX];
    int tam;

    void start() {
        tam = 1;
        memset(go, -1, sizeof(go));
        memset(lnk, -1, sizeof(lnk));
        memset(ex, -1, sizeof(ex));
    }

    void add_string(string &t) {
        int r = 0;
        for(char ch : t) {
            int c = valor(ch);
            if(go[r][c] == -1) {
                go[r][c] = tam; tam++;
            }
            r = go[r][c];
        }
        output[r] = nmatches[r] = true;
    }

    void build() {
        queue<int> q;
        lnk[0] = ex[0] = 0;
        for(int i=0; i<K; i++) {
            if(go[0][i] == -1) go[0][i] = 0;
            else {
                lnk[go[0][i]] = ex[go[0][i]] = 0;
                q.push(go[0][i]);
            }
        }
        for(;!q.empty(); q.pop()) {
            int v = q.front();
            int u = lnk[v];
            for(int i=0; i<K; i++) {
                if(go[v][i] == -1) go[v][i] = go[u][i];
                else {
                    lnk[go[v][i]] = go[u][i];
                    int w = lnk[go[v][i]];
                    ex[go[v][i]] = (output[w] ? w : ex[w]);
                    nmatches[go[v][i]] += nmatches[w];
                    q.push(go[v][i]);
                }
            }
        }
    }
}