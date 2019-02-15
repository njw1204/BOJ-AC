#include <cstdio>

bool isErased[1000001];

void PrintPrime(int min, int max) {
  isErased[1] = true;

  for (int i = 2; i*i <= max; i++) {
    if (isErased[i]) continue;
    for (int j = i * 2; j <= max; j += i)
      isErased[j] = true;
  }
    
  for (int i = min; i <= max; i++) {
    if (isErased[i] == false)
      printf("%d\n", i);
  }
}

int main() {
  int M, N;
  scanf("%d%d", &M, &N);
  PrintPrime(M, N);
  return 0;
}