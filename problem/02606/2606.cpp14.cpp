#include <iostream>
using namespace std;

bool connect[101][101];

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    connect[x][y] = true;
    connect[y][x] = true;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= N; k++) {
        if (connect[j][i] && connect[i][k]) {
          connect[j][k] = true;
          connect[k][j] = true;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 2; i <= N; i++)
    if (connect[1][i]) ans++;
  cout << ans;
  return 0;
}