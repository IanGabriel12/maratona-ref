// Longest common subsequence
// Maior subsequencia comum de duas strings, EX: "AGGTAB" e "GXTXAYB" tem a LCS = "GTAB"
// Complexidade O(N*M) (tamanho de cada string)
int dp[MAX][MAX];

int lcs(string a, string b) {
  int m = a.size(), n = b.size();
  for(int i=1; i<=m; i++) {
    for(int j=1; j<=n; j++) {
      if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  return dp[m][n];
}
