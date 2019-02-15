#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int parent[1005];
int used[1005];
bool dp[1005];

int Find(int a) {
    if (parent[a]) return parent[a] = Find(parent[a]);
    else return a;
}

void Union(int a, int b) {
    int ppa = Find(a), ppb = Find(b);
    if (ppa == ppb) return;
    parent[ppb] = ppa;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    if (n - k < 0) return cout << "DOOMED", 0;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }

    for (int i = 1; i <= n; i++) {
        used[Find(i)]++;
    }

    vector<int> sizeofJarSet;
    for (int i = 1; i <= n; i++) {
        if (used[i]) {
            sizeofJarSet.push_back(used[i]);
        }
    }

    dp[0] = true;
    for (int i : sizeofJarSet) {
        bool tempDp[1005] = {};
        for (int j = 0; i + j <= n; j++) {
            if (dp[j]) {
                tempDp[i + j] = true;
            }
        }
        for (int j = 0; j <= n; j++) {
            dp[j] |= tempDp[j];
        }
    }

    if (dp[k]) cout << "SAFE";
    else cout << "DOOMED";
}