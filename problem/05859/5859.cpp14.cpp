#include <iostream>
using namespace std;

enum { SAME = 1, DIFF = -1 };
char same[1001][1001];

bool Check2ndValid(int N, int x, int y, char type) {
  bool valid = true;
  int xy[2] = {x,y};
  int T[2];
  if (type == SAME) { T[0] = SAME; T[1] = DIFF; } else { T[0] = DIFF; T[1] = SAME; }
  for (int k = 0; k < 2; k++) {
    int st = xy[k], to = xy[1 - k];
    for (int j = 0; j < N; j++) {
      if (j == x || j == y) continue;
      if (same[st][j] == SAME) {
        if (same[to][j] != T[1]) {
          same[to][j] = T[0];
          same[j][to] = T[0];
        } else valid = false;
      } else if (same[st][j] == DIFF) {
        if (same[to][j] != T[0]) {
          same[to][j] = T[1];
          same[j][to] = T[1];
        } else valid = false;
      }
    }
    if (!valid) break;
  }
  return valid;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, ans;
  bool fail = false;
  cin >> N >> M;
  for (ans = 0; ans < M; ans++) {
    int x, y;
    char type;
    cin >> x >> y >> type;
    type = (type == 'T' ? SAME : DIFF);
    if (same[x][y] == 0) {
      same[x][y] = type;
      same[y][x] = type;
      fail = !(Check2ndValid(N, x, y, type));
    } else if (same[x][y] == -type) fail = true;
    if (fail) break;
  }
  cout << ans;
  return 0;
}