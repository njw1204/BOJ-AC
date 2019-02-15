#include <iostream>
#define MAX(x,y) ((x)>(y)?(x):(y))
using namespace std;

int arr[1000];
int dp[1000];

int main() {
  ios_base::sync_with_stdio(false);
  int N, ans = 1;
  cin >> N;

  for (int i = 0; i < N; i++) cin >> arr[i];
  dp[N - 1] = 1;

  for (int i = N - 2; i >= 0; i--) {
    dp[i] = 1;
      
    for (int j = i + 1; j < N; j++) {
      if (arr[i] < arr[j] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
        ans = MAX(ans, dp[i]);
      }
    }
  }

  cout << ans;
  return 0;
}