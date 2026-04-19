// Crivo de erastótenes O(N)
// lp[i] menor primo que divide i
// pr lista de primos 
const int MAX = 1e7+1;
int lp[MAX];
vi pr;

rep(i, 2, MAX) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
    }
    for (int j = 0; i * pr[j] < MAX; ++j) {
        lp[i * pr[j]] = pr[j];
        if (pr[j] == lp[i]) {
            break;
        }
    }
}
