long long phi[N];

void sieve() {
  memset(phi, 0, sizeof(phi));
  for (int i = 2; i < N; i++) {
    if (!phi[i]) {
      for (int j = i; j < N; j += i) {
        if (!phi[j]) {
          phi[j] = j;
        }
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
}

