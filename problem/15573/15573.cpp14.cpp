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

int N, M, K;
int mine[1001][1001];
bool visit[1001][1001];

int BFS(int D) {
  INIT(visit);
  int ans = 0;
  queue<pair<int, int>> Q;

  for (int i = 1; i <= N; i++) {
    if (mine[i][1] <= D) {
      Q.push({i,1});
      visit[i][1] = true;
      ans++;
    }
    if (M != 1 && mine[i][M] <= D) {
      Q.push({i,M});
      visit[i][M] = true;
      ans++;
    }
  }

  for (int i = 2; i <= M - 1; i++) {
    if (mine[1][i] <= D) {
      Q.push({1,i});
      visit[1][i] = true;
      ans++;
    }
  }

  while (!Q.empty()) {
    pair<int, int> now = Q.front();
    Q.pop();
    if (now.$1 > 1 && mine[now.$1 - 1][now.$2] <= D && visit[now.$1 - 1][now.$2] == false) {
      Q.push({now.$1 - 1,now.$2});
      visit[now.$1 - 1][now.$2] = true;
      ans++;
    }
    if (now.$1 < N && mine[now.$1 + 1][now.$2] <= D && visit[now.$1 + 1][now.$2] == false) {
      Q.push({now.$1 + 1,now.$2});
      visit[now.$1 + 1][now.$2] = true;
      ans++;
    }
    if (now.$2 > 1 && mine[now.$1][now.$2 - 1] <= D && visit[now.$1][now.$2 - 1] == false) {
      Q.push({now.$1,now.$2 - 1});
      visit[now.$1][now.$2 - 1] = true;
      ans++;
    }
    if (now.$2 < M && mine[now.$1][now.$2 + 1] <= D && visit[now.$1][now.$2 + 1] == false) {
      Q.push({now.$1,now.$2 + 1});
      visit[now.$1][now.$2 + 1] = true;
      ans++;
    }
  }

  return ans;
}

int main() {
  UNSYNC; READTXT;
  INPUT3(N, M, K);
  int max_weight = 0, min_weight = INT_MAX;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      INPUT(mine[i][j]);
      max_weight = MAX(max_weight, mine[i][j]);
      min_weight = MIN(min_weight, mine[i][j]);
    }
  }

  int left = min_weight, right = max_weight;
  while (left < right) {
    int mid = (left + right) / 2;
    if (BFS(mid) >= K) right = mid;
    else left = mid + 1;
  }

  PRINT(left);
  return 0;
}