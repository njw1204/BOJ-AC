#include <bits/stdc++.h>
using namespace std;

int n, ans;
char link[2005][2005];
bool visit[2005];
bool visit2[2005];
int color[2005];

pair<int, int> dfs(int si, int siColor) {
    int colorCnt[2] = {0};
    visit[si] = true;
    color[si] = siColor;

    colorCnt[siColor]++;

    for (int i = 1; i <= n; i++) {
        if (link[si][i] == '1' && !visit[i]) {
            auto result = dfs(i, (siColor + 1) % 2);
            colorCnt[0] += result.first;
            colorCnt[1] += result.second;
        }
    }

    return {colorCnt[0], colorCnt[1]};
}

int bfs(int si) {
    queue<int> Q;
    int colorCnt[2] = {0};
    visit2[si] = true;
    color[si] = 0;
    Q.push(si);

    colorCnt[0]++;

    while (!Q.empty()) {
        int i = Q.front(); Q.pop();
        for (int j = 1; j <= n; j++) {
            if (link[i][j] == '1' && !visit2[j]) {
                visit2[j] = true;
                Q.push(j);
                color[j] = (color[i] + 1) % 2;
                colorCnt[color[j]]++;
            }
        }
    }

    return max(colorCnt[0], colorCnt[1]);
}

int main() {
    cin >> n;
    cin.get();
    memset(color, -1, sizeof(color));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            link[i][j] = cin.get();
        }
        cin.get();
    }

    if (cin.get() != EOF) return -1;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (link[i][j] == '1') link[j][i] = '1';
        }
    }


    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            auto result = dfs(i, 0);
            ans += max(result.first, result.second);
        }
    }

    int ans2 = 0;

    for (int i = 1; i <= n; i++) {
        if (!visit2[i]) {
            ans2 += bfs(i);
        }
    }

    if (ans != ans2) return -1;
    return cout << ans, 0;
}