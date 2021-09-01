#include <iostream>
using namespace std;

int main() {
  int N;
  long long dp[90] = {1,1};
  cin >> N;
  for (int i = 2; i < N; i++) {
    dp[i] = dp[i - 2] + dp[i - 1];
  }
  cout << dp[N - 1];
  return 0;
}