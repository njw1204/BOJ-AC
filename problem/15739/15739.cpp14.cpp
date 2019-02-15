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

int sumVal(int n){
  return n * (n * n + 1) / 2;
}

int n;
int arr[100][100];
map<int, bool> asdf;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> arr[i][j];
      if (asdf[arr[i][j]]){
        return puts("FALSE"), 0;
      }
      asdf[arr[i][j]] = true;
    }
  }
  int ds1 = 0, ds2 = 0;
  for (int i = 0; i < n; i++){
    int s1 = 0, s2 = 0;
    for (int j = 0; j < n; j++){
      s1 += arr[i][j];
      s2 += arr[j][i];
    }
    if (s1 != sumVal(n) || s2 != sumVal(n)){
      return puts("FALSE"), 0;
    }
    ds1 += arr[i][i];
    ds2 += arr[i][n - 1 - i];
  }

  if (ds1 != sumVal(n) || ds2 != sumVal(n)){
    return puts("FALSE"), 0;
  }

  puts("TRUE");
  return 0;
}