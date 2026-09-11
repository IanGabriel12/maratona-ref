/**
 * Author: Ian Gabriel
 * Description: Função PI e matching de padrão. pi[i] é o maior j (diferente de i), tal que o prefixo de tamanho j
 * é igual ao sufixo de tamanho j da string s[0..i]. matching(pat, t) usa pi para calcular as posições em que $pat$ ocorre em $t$
 * Time: pi = $O(|s|)$; matching = $O(|pat| + |t|)$
 */
vi pi(string s) {
  vi pi(s.size()); pi[0] = 0;
  for(int i=1, j=0; i<s.size(); i++) {
    while(j && s[i] != s[j]) j = pi[j-1];
    if(s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

vi matching(string &pat, string &t) {
  vi p = pi(pat), match;
  for(int i=0, j=0; i<t.size(); i++) {
    while(j && t[i] != pat[j]) j = p[j-1];
    if(t[i] == pat[j]) j++;
    if(j == pat.size()) match.push_back(i-j+1), j = p[j-1];
  }
  return match;
}