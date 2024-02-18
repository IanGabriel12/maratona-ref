// Crivo de erastótenes
// Encontra todos os primos ate N
// Complexidade O(N log(log N)) (up to 10^8)
bool is_prime[MAX];
vector<int> primes;
void sieve(int n) {
  memset(is_prime, 1, n + 1);
  is_prime[0] = is_prime[1] = false;
  for(int i=2; i<=n; i++) {
    if(!is_prime[i]) continue;
    primes.push_back(i);
    for(int j=i*i; j<=n; j+=i) {
      is_prime[j] = false;
    }
  }
}
