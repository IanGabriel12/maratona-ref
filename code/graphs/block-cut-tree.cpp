// Block Cut Tree
// Cria a block-cut-tree, uma arvore com blocos e pontos
// de articulacao. Funciona em grafos desconexos e que tem
// arestas multiplas.
//
// Os blocos sao as componentes biconexas. Uma componente
// biconexa eh um conjunto de ARESTAS tais que o grafo
// induzido nao possui pontos de articulacao.
// Quaisquer dois vertices em uma componente biconexa possuem
// pelo menos dois caminhos disjuntos em vertices.
// 
// Os pontos de articulacao e os blocos "se alternam", i.e, eles
// formam uma 2-coloracao da arvore.
//
// e[i][j] - id da j-esima aresta do vertice i
// compAresta[i] - bloco da aresta i 
// pontoArt[i] - se > 0 o vertice i eh ponto de articulacao e retorna o id
// dele na arvore.
//
// Complexidade: O(n+m)
// We <3 bct
namespace bct {
    vector<int> g[MAX], e[MAX];
    bool marc[MAX], marcAresta[MAX], marcComp[MAX];
    int lo[MAX], pos[MAX], compAresta[MAX], pontoArt[MAX];
    int t, c;
    stack<int> s;
    vector<int> tree[MAX];

    void createNovaComponente(int idAresta) {
        c++; int curr;
        do {
            curr = s.top();
            s.pop();
            compAresta[curr] = c;
            if(s.empty()) break;
        } while(curr != idAresta);
    }
    void tarjan(int x, int p=-1) {
        marc[x] = true;
        pos[x] = t++;
        lo[x] = pos[x];
        int cntFilhos = 0;

        for(int i=0; i<g[x].size(); i++) {
            int y = g[x][i];
            int idAresta = e[x][i];
            if(marcAresta[idAresta]) continue;
            marcAresta[idAresta] = true;
            s.push(idAresta);

            if(!marc[y]) {
                tarjan(y, x);
                lo[x] = min(lo[x], lo[y]);
                cntFilhos++;
                bool novaComponente = false;
                if(p != -1 && lo[y] >= pos[x]) novaComponente = true;
                if(p == -1 && cntFilhos >= 2) novaComponente = true;
                if(novaComponente) {
                    pontoArt[x] = 1;
                    createNovaComponente(idAresta);
                }
            } else lo[x] = min(lo[x], pos[y]);
        }
    }
    void build(int n) {
        t=0; c=0;
        for(int i=1; i<=n; i++) {
            if(!marc[i]) {
                tarjan(i);
                createNovaComponente(-1);
            }
        }

        for(int i=1; i<=n; i++) {
            if(pontoArt[i] == 0) continue;
            pontoArt[i] = ++c;
            for(int j=0; j<e[i].size(); j++) {
                int idAresta = e[i][j];
                int comp = compAresta[idAresta];
                if(marcComp[comp]) continue;
                marcComp[comp] = true;
                tree[pontoArt[i]].push_back(comp);
                tree[comp].push_back(pontoArt[i]);
            }
            for(int j=0; j<e[i].size(); j++) {
                int idAresta = e[i][j];
                int comp = compAresta[idAresta];
                marcComp[comp] = false;
            }
        }
    }
}