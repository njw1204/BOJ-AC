#include <iostream>
using namespace std;

int main() {
  int N, result=0;
  int dp[100][10] = {0}; // i자리의 끝 숫자가 j인 계단수 개수
  cin >> N;
  for (int i = 1; i < 10; i++) {
    dp[0][i] = 1;
  }
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      if (j > 0 && j < 9)
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
      else if (j == 0)
        dp[i][j] = (dp[i - 1][j + 1]) % 1000000000;
      else
        dp[i][j] = (dp[i - 1][j - 1]) % 1000000000;
    }
  }
  for (int i = 0; i < 10; i++) {
    result += dp[N - 1][i];
    result %= 1000000000;
  }
  cout << result;
  return 0;
}