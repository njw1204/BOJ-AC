#include <iostream>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX3(x,y,z) MAX(MAX(x,y),z)
#define MIN3(x,y,z) MIN(MIN(x,y),z)
using namespace std;

int dp[2][4][2];

int main() {
  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    dp[i%2][1][0] = MIN(dp[(i-1)%2][1][0], dp[(i-1)%2][2][0]) + a;
    dp[i%2][2][0] = MIN3(dp[(i-1)%2][1][0], dp[(i-1)%2][2][0], dp[(i-1)%2][3][0]) + b;
    dp[i%2][3][0] = MIN(dp[(i-1)%2][2][0], dp[(i-1)%2][3][0]) + c;
    dp[i%2][1][1] = MAX(dp[(i-1)%2][1][1], dp[(i-1)%2][2][1]) + a;
    dp[i%2][2][1] = MAX3(dp[(i-1)%2][1][1], dp[(i-1)%2][2][1], dp[(i-1)%2][3][1]) + b;
    dp[i%2][3][1] = MAX(dp[(i-1)%2][2][1], dp[(i-1)%2][3][1]) + c;
  }

  cout << MAX3(dp[N%2][1][1], dp[N%2][2][1], dp[N%2][3][1]) << ' ';
  cout << MIN3(dp[N%2][1][0], dp[N%2][2][0], dp[N%2][3][0]);
  return 0;
}