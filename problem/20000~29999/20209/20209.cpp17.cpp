#include <bits/stdc++.h>
using namespace std;

int N, K;
int ans = INT_MAX;
vector<int> a;
vector<int> b[10];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    
    for (int i = 0; i < K; i++) {
        int x; cin >> x;
        for (int j = 0; j < x; j++) {
            int x2; cin >> x2;
            b[i].push_back(x2 - 1);
        }
    }

    for (int i = 0; i < pow(5, K); i++) {
        vector<int> ta = a;
        int t = i;
        int pushsum = 0;

        for (int j = 0; j < K; j++) {
            int push = t % 5;
            for (auto k : b[j])
                ta[k] = (ta[k] + (j + 1) * push) % 5;
            pushsum += push;
            t /= 5;
        }

        bool isAllSame = true;
        for (int j = 1; j < N; j++) {
            if (ta[j] != ta[j - 1])
                isAllSame = false;
        }

        if (isAllSame) ans = min(ans, pushsum);
    }

    if (ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}