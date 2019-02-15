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

int main() {
  while (1){
    int T;
    cin >> T;
    if (T == 0) break;
    map<int, bool> asdf;
    int before = -1;
    for (int i = 0; i < T; i++){
      int n;
      cin >> n;
      if (n == before) continue;
      cout << n << ' ';
      before = n;
    }
    cout << "$\n";
  }
  return 0;
}

/*
5 1 22 22 22 3
4 98 76 20 76
6 19 19 35 86 86 86
1 7
0

1 22 3 $
98 76 20 76 $
19 35 86 $
7 $
*/