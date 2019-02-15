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
#define REP(i,n) for(ull (i)=0;(i)<(n);(i)++)
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

int box[102][102][102];
int visit[102][102][102];
int ans = 0;
int normal_cnt = 0;

void BFS(queue<vector<int>>& bfs, const vector<int>& pt, const vector<int>& diff) {
  if (box[pt[0] + diff[0]][pt[1] + diff[1]][pt[2] + diff[2]] == 0 &&
      visit[pt[0] + diff[0]][pt[1] + diff[1]][pt[2] + diff[2]] == 0) {
    bfs.push({pt[0] + diff[0],pt[1] + diff[1],pt[2] + diff[2]});
    visit[pt[0] + diff[0]][pt[1] + diff[1]][pt[2] + diff[2]] = visit[pt[0]][pt[1]][pt[2]] + 1;
    ans = MAX(ans, visit[pt[0]][pt[1]][pt[2]] + 1);
    normal_cnt--;
  }
}

int main() {
  UNSYNC; READTXT;
  DINPUT3(X, Y, H);
  queue<vector<int>> bfs;
  int no_cnt = 0;

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= Y; j++) {
      for (int k = 1; k <= X; k++) {
        INPUT(box[i][j][k]);
        if (box[i][j][k] == 1) {
          bfs.push({i,j,k});
          visit[i][j][k] = 1;
        }
        else if (box[i][j][k] == -1) no_cnt++;
        else normal_cnt++;
      }
    }
  }

  for (int i = 0; i < 102; i++) {
    for (int j = 0; j < 102; j++) {
      box[0][i][j] = -1;
      box[i][0][j] = -1;
      box[i][j][0] = -1;
      box[H+1][i][j] = -1;
      box[i][Y+1][j] = -1;
      box[i][j][X+1] = -1;
    }
  }

  if (!bfs.empty() && bfs.size() + no_cnt == X * Y * H) {
    PRINT(0);
    return 0;
  } else if (bfs.empty()) {
    PRINT(-1);
    return 0;
  }

  while (!bfs.empty()) {
    vector<int> pt = bfs.front();
    bfs.pop();
    BFS(bfs, pt, {1,0,0});
    BFS(bfs, pt, {-1,0,0});
    BFS(bfs, pt, {0,1,0});
    BFS(bfs, pt, {0,-1,0});
    BFS(bfs, pt, {0,0,1});
    BFS(bfs, pt, {0,0,-1});
  }

  if (normal_cnt) PRINT(-1);
  else PRINT(ans - 1);
  return 0;
}