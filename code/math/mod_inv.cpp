// Inverso modular (fermat)
int mod_inv(int a) {
  return fast_exp(a, MOD - 2);
}