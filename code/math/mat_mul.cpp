// Multiplicação de matrizes
vector<vector<int>> mat_mul(
  vector<vector<int>> a, 
  vector<vector<int>> b
) {
  int rows = a.size();
  int cols = b[0].size();
  int aux = b.size();
  vector<vector<int>> result(
    rows,
    vector<int>(cols)
  );

  for(int i=0; i<rows; i++) {
    for(int j=0; j<cols; j++) {
      int sum = 0;
      for(int k=0; k<aux; k++) {
        sum += a[i][k] * b[k][j];
      }
      result[i][j] = sum;
    }
  }

  return result;
}