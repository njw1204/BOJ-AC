#include <iostream>
#define MAX(x,y) ((x)>(y)?(x):(y))
using namespace std;

int dp[100][10001];
int memsize[100];
int cost[100];

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> memsize[i];
  for (int i = 0; i < N; i++) cin >> cost[i];

  for (int i = cost[0]; i <= 10000; i++)
    dp[0][i] = memsize[0];

  for (int i = 1; i < N; i++) {
    for (int j = 1; j <= 10000; j++) {
      if (j - cost[i] >= 0)
        dp[i][j] = MAX(dp[i-1][j], dp[i-1][j-cost[i]] + memsize[i]);
      else
        dp[i][j] = dp[i-1][j];
    }
  }

  for (int i = 1; i <= 10000; i++) {
    if (dp[N-1][i] >= M) {
      cout << i;
      return 0;
    }
  }
}