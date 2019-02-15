#include <iostream>
#define _INT_MAX_ 0xFFFFFFF
#define MIN(x,y) (((x)<(y))?(x):(y))
using namespace std;

int top, start, goal, up, down;
int dp[1000001];
bool isChecked[1000001];

int GetShortPath(int now) {
  if (isChecked[now]) return _INT_MAX_;
  else isChecked[now] = true;

  if (now == goal) {
    dp[now] = 0;
    return 0;
  }

  int path_1 = _INT_MAX_, path_2 = _INT_MAX_;

  if (now - down >= 1)
    path_1 = (dp[now - down] == -1) ?
             GetShortPath(now - down) : dp[now - down];
  
  if (now + up <= top)
    path_2 = (dp[now + up] == -1) ?
             GetShortPath(now + up) : dp[now + up];

  dp[now] = MIN(path_1, path_2) + 1;
  return dp[now];
}

int main() {
  cin >> top >> start >> goal >> up >> down;
  for (int i = 0; i < 1000001; i++) dp[i] = -1;

  int result = GetShortPath(start);

  if (result < _INT_MAX_) cout << result;
  else cout << "use the stairs";

  return 0;
}