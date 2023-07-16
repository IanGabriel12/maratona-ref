// Crivo de erastótenes
bool is_prime[MAX];
vector<int> primes;
void sieve() {
  for(int i=2; i<=SQRT_MAX; i++) {
    if(!is_prime[i]) continue;
    primes.push_back(i);
    for(int j=2*i; j<=MAX; j+=i) {
      is_prime[j] = false;
    }
  }
}