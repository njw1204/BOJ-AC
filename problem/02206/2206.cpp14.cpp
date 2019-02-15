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

int field[1004][1004];
int visit[1004][1004][2];

int BFS(int fi, int fj) {
  int maxDepth = 1;
  queue<vector<int>> Q;
  Q.push({2,2,1});
  visit[2][2][1] = 1;

  while (!Q.empty()) {
    vector<int> now = Q.front();
    int i = now[0], j = now[1], chance = now[2];
    if (i == fi && j == fj) return visit[fi][fj][chance];
    Q.pop();

    if (chance) {
      if (field[i - 1][j] == 0 && visit[i - 1][j][1] == 0) {
        Q.push({i - 1,j,1});
        visit[i - 1][j][1] = visit[i][j][1] + 1;
        maxDepth = MAX(maxDepth, visit[i - 1][j][1]);
      }
      if (field[i + 1][j] == 0 && visit[i + 1][j][1] == 0) {
        Q.push({i + 1,j,1});
        visit[i + 1][j][1] = visit[i][j][1] + 1;
        maxDepth = MAX(maxDepth, visit[i + 1][j][1]);
      }
      if (field[i][j - 1] == 0 && visit[i][j - 1][1] == 0) {
        Q.push({i,j - 1,1});
        visit[i][j - 1][1] = visit[i][j][1] + 1;
        maxDepth = MAX(maxDepth, visit[i][j - 1][1]);
      }
      if (field[i][j + 1] == 0 && visit[i][j + 1][1] == 0) {
        Q.push({i,j + 1,1});
        visit[i][j + 1][1] = visit[i][j][1] + 1;
        maxDepth = MAX(maxDepth, visit[i][j + 1][1]);
      }
      if (field[i - 1][j] == 1 && field[i - 2][j] == 0 && visit[i - 2][j][0] == 0) {
        Q.push({i - 2,j,0});
        visit[i - 2][j][0] = visit[i][j][1] + 2;
        maxDepth = MAX(maxDepth, visit[i - 2][j][0]);
      }
      if (field[i + 1][j] == 1 && field[i + 2][j] == 0 && visit[i + 2][j][0] == 0) {
        Q.push({i + 2,j,0});
        visit[i + 2][j][0] = visit[i][j][1] + 2;
        maxDepth = MAX(maxDepth, visit[i + 2][j][0]);
      }
      if (field[i][j - 1] == 1 && field[i][j - 2] == 0 && visit[i][j - 2][0] == 0) {
        Q.push({i,j - 2,0});
        visit[i][j - 2][0] = visit[i][j][1] + 2;
        maxDepth = MAX(maxDepth, visit[i][j - 2][0]);
      }
      if (field[i][j + 1] == 1 && field[i][j + 2] == 0 && visit[i][j + 2][0] == 0) {
        Q.push({i,j + 2,0});
        visit[i][j + 2][0] = visit[i][j][1] + 2;
        maxDepth = MAX(maxDepth, visit[i][j + 2][0]);
      }
    } else {
      if (field[i - 1][j] == 0 && visit[i - 1][j][0] == 0) {
        Q.push({i - 1,j,0});
        visit[i - 1][j][0] = visit[i][j][0] + 1;
        maxDepth = MAX(maxDepth, visit[i - 1][j][0]);
      }
      if (field[i + 1][j] == 0 && visit[i + 1][j][0] == 0) {
        Q.push({i + 1,j,0});
        visit[i + 1][j][0] = visit[i][j][0] + 1;
        maxDepth = MAX(maxDepth, visit[i + 1][j][0]);
      }
      if (field[i][j - 1] == 0 && visit[i][j - 1][0] == 0) {
        Q.push({i,j - 1,0});
        visit[i][j - 1][0] = visit[i][j][0] + 1;
        maxDepth = MAX(maxDepth, visit[i][j - 1][0]);
      }
      if (field[i][j + 1] == 0 && visit[i][j + 1][0] == 0) {
        Q.push({i,j + 1,0});
        visit[i][j + 1][0] = visit[i][j][0] + 1;
        maxDepth = MAX(maxDepth, visit[i][j + 1][0]);
      }
    }
  }

  return -1;
}

int main() {
  READTXT;
  DINPUT2(N, M);

  REP(i, 1004) {
    REP(j, 1004) {
      field[i][j] = 1;
    }
  }

  for (int i = 2; i <= N + 1; i++) {
    for (int j = 2; j <= M + 1; j++) {
      scanf("%1d", field[i] + j);
    }
  }

  PRINT(BFS(N + 1, M + 1));
  return 0;
}