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

int L, R, A;

int main() {
  cin >> L >> R >> A;
  while (A){
    if (L < R){
      L++;
      A--;
    }
    else {
      R++;
      A--;
    }
  }

  while (L != R){
    if (L > R) L--;
    else R--;
  }

  cout << L + R;
  return 0;
}