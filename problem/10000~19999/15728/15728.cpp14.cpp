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

int n, k;
vector<int> gong;
vector<int> team;

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    gong.push_back(s);
  }
  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    team.push_back(s);
  }
  sort(gong.begin(), gong.end());
  int minGong = gong.front(), maxGong = gong.back();

  for (auto& i : team){
    if (i < 0)
      i = i * minGong;
    else
      i = i * maxGong;
  }

  sort(team.begin(), team.end(), greater<int>());
  cout << team[k];
  return 0;
}