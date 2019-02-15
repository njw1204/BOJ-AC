#include <iostream>
#include <cmath>
using namespace std;

int dp[2][1000001] = {{0,1,1},{0,1,-1}};

int main() {
  int N;
  cin >> N;
  if (N == 0) cout << "0\n0";
  else if (N > 0) {
    for (int i = 3; i <= N; i++)
      dp[0][i] = (dp[0][i - 1] + dp[0][i - 2]) % 1000000000;
      
    cout << "1\n" << dp[0][N] % 1000000000;
  } else {
    for (int i = -3; i >= N; i--)
      dp[1][-i] = (dp[1][-(i + 2)] - dp[1][-(i + 1)]) % 1000000000;
      
    if (dp[1][-N] > 0) cout << "1\n";
    else cout << "-1\n";
    cout << abs(dp[1][-N] % 1000000000);
  }

  return 0;
}