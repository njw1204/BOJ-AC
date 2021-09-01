#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005] = {0};

int main() {
    int c;
    cin >> c;
    
    for (int i = 0; i < c; i++) {
        int s, t, ans = 9999999;

        for (int j = 0; j <= 1000; j++)
            for (int k = 0; k <= 1000; k++)
                dp[j][k] = 9999999;

        cin >> s >> t;
        dp[s][t] = 0;

        for (int j = 1; j <= 500; j++) {
            for (int k = 1; k <= 500; k++) {
                dp[j + 1][k] = min(dp[j + 1][k], dp[j][k] + 1);
                dp[j * 2][k + 3] = min(dp[j * 2][k + 3], dp[j][k] + 1);
                if (j == k) ans = min(ans, dp[j][k]);
            }
        }

        cout << ans << '\n';
    }
}