template<int MOD> struct mint {
    ll v;
    mint(): v(0) {}
    mint(ll _v) : v(_v) {}
    mint operator*(mint &r) { return mint(v*r.v%MOD); }
    mint operator+(mint &r) { return mint((v+r.v)%MOD); }
    mint operator-(mint &r) { return mint((MOD+v-r.v)%MOD); }
    mint* operator*=(mint &r) { this->v*=r.v; this->v%=MOD; return this; }
    mint* operator+=(mint &r) { this->v+=r.v; this->v%=MOD; return this; }
};
template<int MOD> mint<MOD> pw(mint<MOD> a, ll e) {
    mint<MOD> p = a, ans = mint<MOD>(1);
    while(e) {
        if(e&1) ans *= p;
        p*=p;
        e >>= 1;
    }
    return ans;
}
template<int MOD> mint<MOD> inv(mint<MOD> a) { return pw<MOD>(a, MOD-2); }