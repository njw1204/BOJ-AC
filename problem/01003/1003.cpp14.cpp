#include <iostream>

int fibo_zero_count[41] = {0};
int fibo_one_count[41] = {0};

void fibocount(int n) {
  for (int i = 0; i <= n; i++) {
    if (i == 0) {
      fibo_zero_count[i]=1;
    } else if (i == 1) {
      fibo_one_count[i]=1;
    } else if (fibo_zero_count[i]==0 && fibo_one_count[i]==0) {
      fibo_zero_count[i] = fibo_zero_count[i - 1] + fibo_zero_count[i - 2];
      fibo_one_count[i] = fibo_one_count[i - 1] + fibo_one_count[i - 2];
    }
  }
  printf("%d %d", fibo_zero_count[n], fibo_one_count[n]);
}

int main() {
  int T;
  scanf("%d", &T);
  int* fibo_case = new int[T];
  for (int i = 0; i < T; i++) {
    scanf("%d", fibo_case + i);
  }
  for (int i = 0; i < T; i++) {
    fibocount(fibo_case[i]);
    if (i != T - 1) printf("\n");
  }
  delete[] fibo_case;
  return 0;
}