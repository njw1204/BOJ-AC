#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 2; N > 1; i++) {
    while (N%i == 0) {
      N /= i;
      printf("%d\n", i);
    }
  }
  return 0;
}