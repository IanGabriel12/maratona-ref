const int MOD = 1e9+7;
struct mint {
    ll v;
    mint(): v(0) {}
    mint(ll _v) : v(_v) {}
    mint operator*(mint &r) { return mint(v*r.v%MOD); }
    mint operator+(mint &r) { return mint((v+r.v)%MOD); }
    mint operator-(mint &r) { return mint((MOD+v-r.v)%MOD); }
    mint* operator*=(mint &r) { this->v*=r.v; this->v%=MOD; return this; }
    mint* operator+=(mint &r) { this->v+=r.v; this->v%=MOD; return this; }
};
mint pw(mint a, int e) {
    mint p = a, ans = mint(1);
    while(e) {
        if(e&1) ans *= p;
        p*=p;
        e >>= 1;
    }
    return ans;
}
mint inv(mint a) { return pw(a, MOD-2); }