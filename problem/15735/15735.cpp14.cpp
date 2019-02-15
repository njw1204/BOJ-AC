#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
using namespace std;

int n;
long long dp[10001] = {0,1};
int flag = 0;
int level = 1;
int levelUpper = 1;

int main() {
  cin >> n;
  for (int i = 2; i <= n; i++)
    dp[i] = dp[i - 1] + i * (i + 1) / 2;
  for (int i = 2; i <= n; i++){
    dp[n] += level;
    flag++;
    if (flag % 2 == 0) levelUpper++;
    level += levelUpper;
  }
  cout << dp[n];
  return 0;
}