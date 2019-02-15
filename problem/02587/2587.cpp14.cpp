#include <stdio.h>
#include <algorithm>

int main() {
  int N[5];
  for (int i = 0; i < 5; i++) scanf("%d", N + i);
  printf("%d\n",(N[0] + N[1] + N[2] + N[3] + N[4]) / 5);
  std::sort(N, N + 5);
  printf("%d", N[2]);
  return 0;
}