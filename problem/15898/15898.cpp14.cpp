#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <bitset>
#include <limits>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
using namespace std;
typedef unsigned int ui;
typedef long long int ll;
typedef unsigned long long int ull;
#define $1 first
#define $2 second
#define pb push_back
#define INF 0x5A5B5C5D
#define INF2 0x77777777
#define PI 3.1415926535897932
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX3(x,y,z) MAX(MAX(x,y),z)
#define MIN3(x,y,z) MIN(MIN(x,y),z)
#define MAX4(a,b,c,d) MAX(MAX3(a,b,c),d)
#define MIN4(a,b,c,d) MIN(MIN3(a,b,c),d)
#define MID(x,y,z) MIN(MAX(x,y),z)==z?MAX(MIN(x,y),z):MAX(x,y)
#define REP(i,n) for(ull (i)=0;(i)<ull(n);(i)++)
#define ALL(list) (list).begin(),(list).end()
#define PRESENT(list,x) (find(ALL(list),x)!=(list).end())
#define INPUT(cin_a) cin>>(cin_a)
#define INPUT2(cin_a,cin_b) cin>>(cin_a)>>(cin_b)
#define INPUT3(cin_a,cin_b,cin_c) cin>>(cin_a)>>(cin_b)>>(cin_c)
#define INPUT4(cin_a,cin_b,cin_c,cin_d) cin>>(cin_a)>>(cin_b)>>(cin_c)>>(cin_d)
#define DINPUT(int_a) int (int_a);INPUT(int_a)
#define DINPUT2(int_a,int_b) int (int_a),(int_b);INPUT2(int_a,int_b)
#define DINPUT3(int_a,int_b,int_c) int (int_a),(int_b),(int_c);INPUT3(int_a,int_b,int_c)
#define DINPUT4(int_a,int_b,int_c,int_d) int (int_a),(int_b),(int_c),(int_d);INPUT4(int_a,int_b,int_c,int_d)
#define TESTCASE(T) DINPUT(i_i__ai);for(int (T)=1;(T)<=i_i__ai;(T)++)
#define INIT(arr) memset((arr),0,sizeof(arr))
#define FILL(a,x) for(auto& acm_icpc:(a))acm_icpc=(x);
#define BETWEEN(x,low,high) ((x)>=(low)&&(x)<=(high))
#define countof(arr) (sizeof(arr)/sizeof((arr)[0]))
#define endl '\n'
#define PRINT(cout_x) cout<<(cout_x)<<endl
#define DEBUG(cout_x) cout<<">> "<<#cout_x<<" = "<<(cout_x)<<endl
#ifdef LOCAL_ALGO
#define READTXT freopen(TXTPATH,"r",stdin)
#define UNSYNC ios_base::sync_with_stdio(false)
#else
#define READTXT
#define UNSYNC ios_base::sync_with_stdio(false);cin.tie(nullptr)
#endif
#define TXTPATH "_input.txt"
inline ull GCD(ull a, ull b) { while (b != 0) { ull t = a % b; a = b; b = t; } return a; }
inline ull LCM(ull a, ull b) { return a * b / GCD(a, b); }
inline ull POW(ull a, ull b, ull m = ULLONG_MAX) { ull r = 1;	while (b) { if (b & 1) r = r * a % m; b >>= 1; a = a * a % m; } return r; }

struct Item {
  int val[4][4];
  char color[4][4];
};

int n;
Item item[10];

int solve(int a, int b, int c, int adir, int bdir, int cdir, int apos, int bpos, int cpos) {
  Item temp[3];

  for (int ii = 0; ii < 3; ii++) {
    int key, sel;
    if (ii == 0) {
      key = adir;
      sel = a;
    }
    else if (ii == 1) {
      key = bdir;
      sel = b;
    }
    else {
      key = cdir;
      sel = c;
    }

    switch (key) {
    case 0:
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          temp[ii].val[i][j] = item[sel].val[i][j];
          temp[ii].color[i][j] = item[sel].color[i][j];
        }
      }
      break;
    case 1:
      for (int i = 0; i < 4; i++) {
        for (int j = 3; j >= 0; j--) {
          temp[ii].val[i][3 - j] = item[sel].val[j][i];
          temp[ii].color[i][3 - j] = item[sel].color[j][i];
        }
      }
      break;
    case 2:
      for (int i = 3; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
          temp[ii].val[3 - i][3 - j] = item[sel].val[i][j];
          temp[ii].color[3 - i][3 - j] = item[sel].color[i][j];
        }
      }
      break;
    case 3:
      for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
          temp[ii].val[3 - i][j] = item[sel].val[j][i];
          temp[ii].color[3 - i][j] = item[sel].color[j][i];
        }
      }
      break;
    }
  }

  int nowVal[5][5] = {0};
  int nowColor[5][5] = {0};

  for (int ii = 0; ii < 3; ii++) {
    int key;
    if (ii == 0) {
      key = apos;
    }
    else if (ii == 1) {
      key = bpos;
    }
    else {
      key = cpos;
    }

    int mi = 0, mj = 0;
    switch (key) {
    case 1:
      mi = 1;
      break;
    case 2:
      mj = 1;
      break;
    case 3:
      mi = 1;
      mj = 1;
      break;
    }

    for (int i = mi; i < mi + 4; i++) {
      for (int j = mj; j < mj + 4; j++) {
        nowVal[i][j] += temp[ii].val[i - mi][j - mj];
        if (nowVal[i][j] < 0) nowVal[i][j] = 0;
        else if (nowVal[i][j] > 9) nowVal[i][j] = 9;
        switch (temp[ii].color[i - mi][j - mj]) {
        case 'R':
          nowColor[i][j] = 7;
          break;
        case 'B':
          nowColor[i][j] = 5;
          break;
        case 'G':
          nowColor[i][j] = 3;
          break;
        case 'Y':
          nowColor[i][j] = 2;
          break;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      ans += nowVal[i][j] * nowColor[i][j];
    }
  }

  return ans;
}

int main() {
  READTXT;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        cin >> item[i].val[j][k];
      }
    }
    getchar();
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        scanf("%c ", &item[i].color[j][k]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (i == j || j == k || i == k) continue;
        for (int ii = 0; ii < 4; ii++) {
          for (int jj = 0; jj < 4; jj++) {
            for (int kk = 0; kk < 4; kk++) {
              for (int iii = 0; iii < 4; iii++) {
                for (int jjj = 0; jjj < 4; jjj++) {
                  for (int kkk = 0; kkk < 4; kkk++) {
                    ans = MAX(ans, solve(i, j, k, ii, jj, kk, iii, jjj, kkk));
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  return cout << ans, 0;
}