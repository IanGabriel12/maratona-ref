/* Prefix function
  pi[i] = tamanho do maior prefixo de s que é sufixo de s[0..i] - O(|s|)
  matching(s, t) = posições de t onde s ocorre - O(|s|+|t|)
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

vi matching(string &s, string &t) {
  vi p = pi(s), match;
  for(int i=0, j=0; i<t.size(); i++) {
    while(j && t[i] != s[j]) j = p[j-1];
    if(t[i] == s[j]) j++;
    if(j == s.size()) match.push_back(i-j+1), j = p[j-1];
  }
  return match;
}