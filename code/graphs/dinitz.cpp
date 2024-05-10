// Fluxo máximo (Dinic/Dinitz)
struct FlowEdge {
    int u, v;
    ll cap, flow = 0;
    FlowEdge(int u, int v, ll cap) : u(u), v(v), cap(cap) {}
    ll pushable() {
        return cap - flow;
    }
};
 
struct Dinic {
    ll flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    vector<int> level, ptr;
    int n, m = 0;
    int s, t;
    queue<int> q;
 
    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        ptr.resize(n);
        level.resize(n);
    }
 
    void addEdge(int u, int v, ll cap) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
        adj[u].push_back(m);
        adj[v].push_back(m+1);
        m += 2;
    }
 
    bool bfs() {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        q.push(s);
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int id : adj[v]) {
                if(level[edges[id].v] != -1) continue;
                if(edges[id].pushable() < 1) continue;
                level[edges[id].v] = level[v] + 1;
                q.push(edges[id].v);
            }
        }
        return level[t] != -1;
    }
 
    ll dfs(int u, ll pushed) {
        if(pushed == 0) return 0;
        if(u == t) return pushed;
 
        for(int &cid = ptr[u]; cid < (int)adj[u].size(); ++cid) {
            int id = adj[u][cid];
            int v = edges[id].v;
            if(level[v] != level[u] + 1) continue;
            if(edges[id].pushable() < 1) continue;
 
            ll new_flow = dfs(v, min(edges[id].pushable(), pushed));
            if(new_flow == 0) continue;
            edges[id].flow += new_flow;
            edges[id ^ 1].flow -= new_flow;
            return new_flow;
        }
        return 0;
    }
 
    ll flow() {
        ll f = 0;
        while(1) {
            if(!bfs()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while(ll pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};