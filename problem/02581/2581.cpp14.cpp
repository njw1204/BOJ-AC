#include <iostream>
using namespace std;

void FindPrime(int min, int max, int* result_sum, int* result_min) {
  bool isErased[10001] = {};
  isErased[1] = true;
  *result_sum = 0, *result_min = 0;

  for (int i = 2; i*i <= max; i++) {
    if (isErased[i]) continue;
    for (int j = i*2; j <= max; j += i) {
      isErased[j] = true;
    }
  }

  for (int i = min; i <= max; i++) {
    if (isErased[i] == false) {
      *result_sum += i;
      if (*result_min == 0) *result_min = i;
    }
  }
}

int main() {
  int M, N, sum, min;
  cin >> M >> N;

  FindPrime(M, N, &sum, &min);

  if (sum == 0) cout << -1;
  else cout << sum << '\n' << min;
  return 0;
}