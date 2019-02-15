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

int arr[1000005];
int ans;

int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> arr[i];
  }
  for (int i = 0; i < N; i++){
    if (arr[i] % 2){
      arr[i]++;
      arr[i + 1]++;
      arr[i + 2]++;
      ans++;
    }
  }
  cout << ans;
  return 0;
}