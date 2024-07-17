// Suffix Array + LCP
/**
 * Ordena p de acordo com as chaves em c.
 * Complexidade: O(n)
 */
void radix(vector<int> &p, vector<int> &c) {
    int n = p.size();
    vector<int> cnt(n), pos(n);
    vector<int> p_new(n);
    for(auto x : c) cnt[x]++;
    pos[0] = 0;
    for(int i=1; i<n; i++) pos[i] = pos[i-1] + cnt[i-1];
    for(int i=0; i<n; i++) {
        int ci = c[p[i]];
        p_new[pos[ci]++] = p[i];
    }
    p = p_new;
}

/**
 * Constroi o suffix array da string s.
 * Complexidade: O(n log n)
 * p -> suffix array de s
 * c[i] -> posicao do sufixo i em p
 */
pair<vector<int>, vector<int>> build_sa(string &s) {
    s.push_back('$');
    int n = s.size();
    vector<int> p(n), c(n);
    vector<pair<char, int>> a(n);
    for(int i=0; i<n; i++) a[i] = {s[i], i};
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++) p[i] = a[i].second;
    c[p[0]] = 0;
    for(int i=1; i<n; i++) {
        if(a[i].first == a[i-1].first) {
            c[p[i]] = c[p[i-1]];
        } else {
            c[p[i]] = c[p[i-1]] + 1;
        }
    }

    int k = 0;
    while((1 << k) < n) {
        for(int i=0; i<n; i++) {
            p[i] = (p[i] - (1 << k) + n) % n;
        }
        radix(p, c);
        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for(int i=1; i<n; i++) {
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << k)) % n]};
            pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            if(now == prev) {
                c_new[p[i]] = c_new[p[i-1]];
            } else {
                c_new[p[i]] = c_new[p[i-1]] + 1;
            }
        }
        c = c_new;
        k++;
    }
    return {p, c};
}

/**
 * Constroi o array LCP a partir do suffix array de s.
 * Complexidade: O(n)
 * lcp[i] -> lcp de p[i] e p[i-1]
 */
vector<int> kasai(vector<int> &p, vector<int> &c, string &s) {
    int n = s.size();
    vector<int> lcp(n);
    int k = 0;
    for(int i=0; i<n-1; i++) {
        int pi = c[i];
        int j = p[pi-1];
        while(s[i+k] == s[j+k]) k++;
        lcp[pi] = k;
        k = max(k-1, 0);
    }
    return lcp;
}