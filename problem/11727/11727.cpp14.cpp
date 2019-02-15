#include <iostream>
using namespace std;

int main() {
  int dp[1001] = {0,1,3};
  int N;
  cin >> N;
  
  for (int i = 3; i <= N; i++)
    dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;

  cout << dp[N] % 10007;
  return 0;
}