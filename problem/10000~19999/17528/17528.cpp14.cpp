#include <bits/stdc++.h>
using namespace std;

int dp[2][62505];
vector<pair<int, int>> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    arr.push_back({0,0});
        
    int N, ans = INT_MAX, sumB = 0;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
    	int x, y;
    	cin >> x >> y;
        arr.push_back({x,y});
        sumB += y;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 62500; j++) {
            if (j < arr[i].first) {
                dp[i % 2][j] = dp[(i - 1) % 2][j];
            }
            else {
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[(i - 1) % 2][j - arr[i].first] + arr[i].second);
            }
            ans = min(ans, max(j, sumB - dp[i % 2][j]));
        }
    }
    
    cout << ans << '\n';
    return 0;
}