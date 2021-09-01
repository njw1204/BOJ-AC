#include <iostream>

#include <string>

#include <map>

#include <vector>

#include <cstring>

#include <algorithm>

#include <climits>

using namespace std;

typedef long long int ll;

ll dp[1005][1005][5];

int field[1005][1005];

int main() {

	int n, m;	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= m; j++) {

			cin >> field[i][j];

		}

	}

	for (int i = 0; i <= n + 1; i++) {

		for (int j = 0; j <= m + 1; j++) {

			dp[i][j][1] = INT_MAX;

			dp[i][j][2] = INT_MAX;

			dp[i][j][3] = INT_MAX;

		}

	}

	for (int i = 1; i <= m; i++) {

		dp[1][i][1] = field[1][i];

		dp[1][i][2] = field[1][i];

		dp[1][i][3] = field[1][i];

	}

	for (int i = 2; i <= n; i++) {

		for (int j = 1; j <= m; j++) {

			dp[i][j][1] = min(dp[i - 1][j + 1][2], dp[i - 1][j + 1][3]) + field[i][j];

			dp[i][j][2] = min(dp[i - 1][j][1], dp[i - 1][j][3]) + field[i][j];

			dp[i][j][3] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + field[i][j];

		}

	}

	ll ans = LLONG_MAX;

	for (int i = 1; i <= m; i++) {

		for (int j = 1; j <= 3; j++) {

			ans = min(ans, dp[n][i][j]);

		}

	}

	cout << ans;

	return 0;

}