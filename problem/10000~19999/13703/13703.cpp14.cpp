#include <iostream>
using namespace std;

long long dp[140][140];
long long ans;

int main() {
	int k, n;
	cin >> k >> n;

	if (n == 0 && k > 0) {
		ans = 1;
	}
	else if (k == 0) {
		ans = 0;
	}
	else {
		dp[0][k] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < 140; j++) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
				if (i == n) {
					ans += dp[i][j];
				}
			}
		}
	}

	cout << ans;
}