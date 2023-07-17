// KMP
int back[MAX];
void kmp_preprocess(string s) {
  int i = 1, j = 0;
  back[0] = 0;
  while(i < s.size()) {
    while(j > 0 && s[i] != s[j]) j = back[j-1];
    if(s[i] == s[j]) j++;
    back[i] = j;
    i++;
  }
}

void kmp_substr(string s, string t) {
  int i=0, j=0;
  while(i < s.size()) {
    while(j > 0 && s[i] != t[j]) j = back[j-1];
    if(s[i] == t[j]) {
      j++;
      if(j == t.size()) {
        // t substr of s
        j = back[j-1];
      }
    }
    i++;
  }
}