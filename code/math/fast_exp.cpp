// Exponenciação rápida
int fast_exp(int base, int exp) {
  if(exp == 0) return 1;
  int raiz = fast_exp(base, exp / 2);
  if(exp % 2 == 0) {
    return raiz*raiz;
  }
  return raiz*raiz*base;
}