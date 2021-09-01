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
#define ABS(x) ((x)>=0?(x):-(x))
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

int ei, ej, er, M, N;
int field[110][110];
int visit[110][110][5];

const int UP = 4, RIGHT = 1, DOWN = 3, LEFT = 2;

int BFS(int si, int sj, int sr) {
  queue<vector<int>> Q;
  Q.push({si,sj,sr});
  visit[si][sj][sr] = 1;
  while (1) {
    vector<int> pos = Q.front();
    Q.pop();
    si = pos[0]; sj = pos[1]; sr = pos[2];
    if (pos[0] == ei && pos[1] == ej && pos[2] == er) {
      return visit[ei][ej][er] - 1;
    }
    switch (pos[2]) {
    case UP:
      if (!visit[si][sj][LEFT]) {
        visit[si][sj][LEFT] = visit[si][sj][sr] + 1;
        Q.push({si,sj,LEFT});
      }
      if (!visit[si][sj][RIGHT]) {
        visit[si][sj][RIGHT] = visit[si][sj][sr] + 1;
        Q.push({ si,sj,RIGHT });
      }
      for (int i = 1; i <= 3; i++) {
        if (si - i >= 0 && !visit[si - i][sj][sr]) {
          int fieldValue = 0;
          for (int j = 1; j <= i; j++) fieldValue += field[si - j][sj];
          if (fieldValue == 0) {
            visit[si - i][sj][sr] = visit[si][sj][sr] + 1;
            Q.push({ si - i,sj,sr });
          }
        }
      }
      break;
    case RIGHT:
      if (!visit[si][sj][UP]) {
        visit[si][sj][UP] = visit[si][sj][sr] + 1;
        Q.push({ si,sj,UP });
      }
      if (!visit[si][sj][DOWN]) {
        visit[si][sj][DOWN] = visit[si][sj][sr] + 1;
        Q.push({ si,sj,DOWN });
      }
      for (int i = 1; i <= 3; i++) {
        if (sj + i < N && !visit[si][sj + i][sr]) {
          int fieldValue = 0;
          for (int j = 1; j <= i; j++) fieldValue += field[si][sj + j];
          if (fieldValue == 0) {
            visit[si][sj + i][sr] = visit[si][sj][sr] + 1;
            Q.push({ si,sj + i,sr });
          }
        }
      }
      break;
    case DOWN:
      if (!visit[si][sj][LEFT]) {
        visit[si][sj][LEFT] = visit[si][sj][sr] + 1;
        Q.push({ si,sj,LEFT });
      }
      if (!visit[si][sj][RIGHT]) {
        visit[si][sj][RIGHT] = visit[si][sj][sr] + 1;
        Q.push({ si,sj,RIGHT });
      }
      for (int i = 1; i <= 3; i++) {
        if (si + i < M && !visit[si + i][sj][sr]) {
          int fieldValue = 0;
          for (int j = 1; j <= i; j++) fieldValue += field[si + j][sj];
          if (fieldValue == 0) {
            visit[si + i][sj][sr] = visit[si][sj][sr] + 1;
            Q.push({ si + i,sj,sr });
          }
        }
      }
      break;
    case LEFT:
      if (!visit[si][sj][UP]) {
        visit[si][sj][UP] = visit[si][sj][sr] + 1;
        Q.push({ si,sj,UP });
      }
      if (!visit[si][sj][DOWN]) {
        visit[si][sj][DOWN] = visit[si][sj][sr] + 1;
        Q.push({ si,sj,DOWN });
      }
      for (int i = 1; i <= 3; i++) {
        if (sj - i >= 0 && !visit[si][sj - i][sr]) {
          int fieldValue = 0;
          for (int j = 1; j <= i; j++) fieldValue += field[si][sj - j];
          if (fieldValue == 0) {
            visit[si][sj - i][sr] = visit[si][sj][sr] + 1;
            Q.push({ si,sj - i,sr });
          }
        }
      }
      break;
    }
  }
}

int main() {
  UNSYNC;
  INPUT2(M, N);
  REP(i, M) {
    REP(j, N) {
      INPUT(field[i][j]);
    }
  }
  DINPUT3(si, sj, sr);
  INPUT3(ei, ej, er);
  si--; sj--; ei--; ej--;
  PRINT(BFS(si, sj, sr));
  return 0;
}