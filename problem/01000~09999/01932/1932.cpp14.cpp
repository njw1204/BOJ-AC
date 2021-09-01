#include <iostream>
using namespace std;

inline int MAX(int x, int y) {
  return (x > y) ? x : y;
}

int main() {
  int N;
  int dp[500][500] = {0};
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i + 1; j++) {
      int input;
      cin >> input;

      if (i == 0)
        dp[i][j] = input;
      else if (j == 0)
        dp[i][j] = input + dp[i - 1][j];
      else if (j == i)
        dp[i][j] = input + dp[i - 1][j - 1];
      else
        dp[i][j] = input + MAX(dp[i - 1][j - 1], dp[i - 1][j]);
    }
  }

  int max_value = -1;
  for (int i = 0; i < N; i++) {
    if (dp[N - 1][i] > max_value) max_value = dp[N - 1][i];
  }

  cout << max_value;
  return 0;
}