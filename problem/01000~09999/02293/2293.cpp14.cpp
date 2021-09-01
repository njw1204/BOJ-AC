#include <iostream>
using namespace std;

int kind[100];
int dp[10001] = {1};

int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> kind[i];

  for (int i = 0; i < n; i++) {
    for (int j = kind[i]; j <= k; j++)
      dp[j] += dp[j - kind[i]];
  }

  cout << dp[k];
  return 0;
}