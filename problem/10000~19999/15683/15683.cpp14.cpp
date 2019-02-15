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
#define ABS(x) (((x)>=0)?(x):-(x))
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX3(x,y,z) MAX(MAX(x,y),z)
#define MIN3(x,y,z) MIN(MIN(x,y),z)
#define MAX4(a,b,c,d) MAX(MAX3(a,b,c),d)
#define MIN4(a,b,c,d) MIN(MIN3(a,b,c),d)
#define MEDIAN(x,y,z) MIN(MAX(x,y),z)==z?MAX(MIN(x,y),z):MAX(x,y)
#define REP(i,n) for(ull (i)=0;(i)<ull(n);(i)++)
#define ALL(list) (list).begin(),(list).end()
#define PRESENT(list,x) (find(ALL(list),x)!=(list).end())
#define INPUT(cin_a) cin>>(cin_a)
#define INPUT2(cin_a,cin_b) cin>>(cin_a)>>(cin_b)
#define INPUT3(cin_a,cin_b,cin_c) cin>>(cin_a)>>(cin_b)>>(cin_c)
#define DINPUT(int_a) int (int_a);INPUT(int_a)
#define DINPUT2(int_a,int_b) int (int_a),(int_b);INPUT2(int_a,int_b)
#define DINPUT3(int_a,int_b,int_c) int (int_a),(int_b),(int_c);INPUT3(int_a,int_b,int_c)
#define DSCANF(int_a) int (int_a);scanf("%d",&(int_a))
#define DSCANF2(int_a,int_b) int (int_a),(int_b);scanf("%d%d",&(int_a),&(int_b))
#define DSCANF3(int_a,int_b,int_c) int (int_a),(int_b),(int_c);scanf("%d%d%d",&(int_a),&(int_b),&(int_c))
#define TESTCASE(T) DINPUT(i_i__ai);for(int (T)=1;(T)<=i_i__ai;(T)++)
#define INIT(arr) memset((arr),0,sizeof(arr))
#define FILL(a,x) for(auto& acm_icpc:(a))acm_icpc=(x);
#define BETWEEN(x,low,high) ((x)>=(low)&&(x)<=(high))
#define ctoi(ch) ((ch)-'0')
#define countof(arr) (sizeof(arr)/sizeof((arr)[0]))
#define endl '\n'
#define PRINT(cout_x) cout<<(cout_x)<<endl
#define DEBUG(cout_x) cout<<">> "<<#cout_x<<" = "<<(cout_x)<<endl
#ifndef ONLINE_JUDGE
#define READTXT freopen(TXTPATH,"r",stdin)
#define UNSYNC ios_base::sync_with_stdio(false)
#else
#define READTXT
#define UNSYNC ios_base::sync_with_stdio(false);cin.tie(nullptr)
#endif
#define TXTPATH "_input.txt"
inline ull GCD(ull a, ull b) { while (b != 0) { ull t = a % b; a = b; b = t; } return a; }
inline ull LCM(ull a, ull b) { return a * b / GCD(a, b); }

int N, M;
int field[10][10];
int temp[10][10];
vector<vector<int>> cctvInfo;
const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;

void copyField() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      temp[i][j] = field[i][j];
    }
  }
}

void fillRaw(int si, int sj, int dir) {
  if (dir == UP) {
    for (int i = si; i >= 1 && field[i][sj] != 6; i--)
      temp[i][sj] = 7;
  }
  if (dir == DOWN) {
    for (int i = si; i <= N && field[i][sj] != 6; i++)
      temp[i][sj] = 7;
  }
  if (dir == LEFT) {
    for (int j = sj; j >= 1 && field[si][j] != 6; j--)
      temp[si][j] = 7;
  }
  if (dir == RIGHT) {
    for (int j = sj; j <= M && field[si][j] != 6; j++)
      temp[si][j] = 7;
  }
}

void fill(int cctvNo, int dir) {
  int type = cctvInfo[cctvNo][0];
  int si = cctvInfo[cctvNo][1], sj = cctvInfo[cctvNo][2];
  if (type == 1) {
    switch (dir) {
    case 0:
      fillRaw(si, sj, RIGHT);
      break;
    case 1:
      fillRaw(si, sj, DOWN);
      break;
    case 2:
      fillRaw(si, sj, LEFT);
      break;
    case 3:
      fillRaw(si, sj, UP);
      break;
    }
  }
  if (type == 2) {
    switch (dir) {
    case 0: case 2:
      fillRaw(si, sj, LEFT);
      fillRaw(si, sj, RIGHT);
      break;
    case 1: case 3:
      fillRaw(si, sj, UP);
      fillRaw(si, sj, DOWN);
      break;
    }
  }
  if (type == 3) {
    switch (dir) {
    case 0:
      fillRaw(si, sj, UP);
      fillRaw(si, sj, RIGHT);
      break;
    case 1:
      fillRaw(si, sj, RIGHT);
      fillRaw(si, sj, DOWN);
      break;
    case 2:;
      fillRaw(si, sj, DOWN);
      fillRaw(si, sj, LEFT);
      break;
    case 3:
      fillRaw(si, sj, LEFT);
      fillRaw(si, sj, UP);
      break;
    }
  }
  if (type == 4) {
    switch (dir) {
    case 0:
      fillRaw(si, sj, LEFT);
      fillRaw(si, sj, UP);
      fillRaw(si, sj, RIGHT);
      break;
    case 1:
      fillRaw(si, sj, UP);
      fillRaw(si, sj, RIGHT);
      fillRaw(si, sj, DOWN);
      break;
    case 2:
      fillRaw(si, sj, RIGHT);
      fillRaw(si, sj, DOWN);
      fillRaw(si, sj, LEFT);
      break;
    case 3:
      fillRaw(si, sj, DOWN);
      fillRaw(si, sj, LEFT);
      fillRaw(si, sj, UP);
      break;
    }
  }
  if (type == 5) {
    fillRaw(si, sj, RIGHT);
    fillRaw(si, sj, DOWN);
    fillRaw(si, sj, LEFT);
    fillRaw(si, sj, UP);
  }
}

int GetSagak() {
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (temp[i][j] == 0) cnt++;
    }
  }
  return cnt;
}

int main() {
  UNSYNC; READTXT;
  int ans = INT_MAX;
  INPUT2(N, M);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> field[i][j];
      if (field[i][j] >= 1 && field[i][j] <= 5) {
        cctvInfo.pb({field[i][j],i,j});
      }
    }
  }
  int xd = (int)pow(4, cctvInfo.size());
  for (int i = 0; i < xd; i++) {
    copyField();
    int t = i;
    for (int j = 0; j < cctvInfo.size(); j++) {
      int dir = t % 4;
      fill(j, dir);
      t /= 4;
    }
    ans = MIN(ans, GetSagak());
  }
  PRINT(ans);
  return 0;
}