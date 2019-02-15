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
#include <random>
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
typedef pair<int, int> pi;
typedef pair<pi, pi> ppi;
typedef pair<ll, ll> pl;
typedef pair<pl, pl> ppl;
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
#define UNSYNC ios_base::sync_with_stdio(false); cin.tie(nullptr)
#endif
#define TXTPATH "_input.txt"
inline ull GCD(ull a, ull b) { while (b != 0) { ull t = a % b; a = b; b = t; } return a; }
inline ull LCM(ull a, ull b) { return a * b / GCD(a, b); }
inline ull POW(ull a, ull b, ull m = ULLONG_MAX) { ull r = 1;	while (b) { if (b & 1) r = r * a % m; b >>= 1; a = a * a % m; } return r; }


int fuck[10][42] =
{
  {
    0,0,0,0,0,0,
    0,0,1,1,0,0,
    0,1,0,0,1,0,
    0,1,0,0,1,0,
    0,1,0,0,1,0,
    0,0,1,1,0,0,
    0,0,0,0,0,0
  },

  {
    0,0,0,0,0,0,
    0,0,0,1,0,0,
    0,0,1,1,0,0,
    0,0,0,1,0,0,
    0,0,0,1,0,0,
    0,0,0,1,0,0,
    0,0,0,0,0,0
  },

  {
    0,0,0,0,0,0,
    0,1,1,1,1,0,
    0,0,0,0,1,0,
    0,1,1,1,1,0,
    0,1,0,0,0,0,
    0,1,1,1,1,0,
    0,0,0,0,0,0
  },

  {
    0,0,0,0,0,0,
    0,1,1,1,0,0,
    0,0,0,0,1,0,
    0,0,0,1,0,0,
    0,0,0,0,1,0,
    0,1,1,1,0,0,
    0,0,0,0,0,0
  },

  {
    0,0,0,0,0,0,
    0,0,0,1,0,0,
    0,0,1,1,0,0,
    0,1,0,1,0,0,
    1,1,1,1,1,0,
    0,0,0,1,0,0,
    0,0,0,0,0,0
  },

  {
    0,0,0,0,0,0,
    0,1,1,1,1,0,
    0,1,0,0,0,0,
    0,1,1,1,0,0,
    0,0,0,0,1,0,
    0,1,0,0,1,0,
    0,0,1,1,0,0
  },

  {
    0,0,0,0,0,0,
    0,1,0,0,0,0,
    0,1,0,0,0,0,
    0,1,1,1,1,0,
    0,1,0,0,1,0,
    0,1,1,1,1,0,
    0,0,0,0,0,0
  },

  {
    0,0,0,0,0,0,
    0,1,1,1,1,0,
    0,0,0,0,1,0,
    0,0,0,1,0,0,
    0,0,0,1,0,0,
    0,0,0,1,0,0,
    0,0,0,0,0,0
  },

  {
    0,0,0,0,0,0,
    0,1,1,1,1,0,
    0,1,0,0,1,0,
    0,1,1,1,1,0,
    0,1,0,0,1,0,
    0,1,1,1,1,0,
    0,0,0,0,0,0
  },

  {
    0,1,1,1,1,0,
    0,1,0,0,1,0,
    0,1,0,0,1,0,
    0,1,1,1,1,0,
    0,0,0,0,1,0,
    0,0,0,0,1,0,
    0,0,0,0,1,0
  }
};

int pan[7][60];
int len;

int Interpret(int start) {
  int raw[42] = {0};
  for (int i = 0; i < 42; i++) {
    raw[i] = pan[i / 6][i % 6 + start];
  }
  for (int i = 0; i <= 9; i++) {
    bool fail = false;
    for (int j = 0; j < 42; j++) {
      if (raw[j] != fuck[i][j]) {
        fail = true;
        break;
      }
    }
    if (!fail) return i;
  }
}

void MakeNumber(int val, int start) {
  for (int i = 0; i < 42; i++) {
    pan[i / 6][i % 6 + start] = fuck[val][i];
  }
}

int main() {
  READTXT;
  int len, i = 0, pos = 0;
  char t;

  while (~scanf("%c", &t)) {
    if (t == '\n') {
      pos++;
      len = i / 6;
      i = 0;
    }
    else {
      pan[pos][i] = t - '0';
      i++;
    }
  }

  vector<int> seq;
  for (int i = 0; i < len; i++) {
    seq.pb(Interpret(i * 6));
  }

  if (next_permutation(ALL(seq))) {
    for (int i = 0; i < len; i++) {
      MakeNumber(seq[i], i * 6);
    }

    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < len * 6; j++) {
        printf("%d", pan[i][j]);
      }
      puts("");
    }
  }
  else {
    return puts("The End"), 0;
  }

  return 0;
}


/*
ll dp[505][505];
int dp_pos[505][505];
bool visit[505][505];
ll value[505][505];
ll ans[505];
int N, M;

ll DFS(int si, int sj) {
  visit[si][sj] = true;

  if (sj == M) {
    dp_pos[si][sj] = si;
    return 0;
  }
  else if (dp[si][sj]) {
    return dp[si][sj];
  }

  pair<int, int> dx[4] = {{1,0},{-1,0},{0,1},{0,-1}};
  vector<pair<pair<int, int>, ll>> dpval;
  
  for (auto ddx : dx) {
    if (si + ddx.$1 < 1 || si + ddx.$1 > N) {
      continue;
    }
    if (sj + ddx.$2 < 1 || sj + ddx.$2 > M) {
      continue;
    }
    if (visit[si + ddx.$1][sj + ddx.$2] && !dp[si + ddx.$1][sj + ddx.$2] && sj + ddx.$2 != M) continue;
    dpval.pb({{si + ddx.$1, sj + ddx.$2}, value[si + ddx.$1][sj + ddx.$2] + DFS(si + ddx.$1, sj + ddx.$2)});
  }

  if (dpval.empty()) {
    puts("Asdf");
  }

  sort(ALL(dpval), [](const auto& a, const auto& b) {
    return a.$2 < b.$2;
  });
  
  dp[si][sj] = dpval[0].$2;
  dp_pos[si][sj] = dp_pos[dpval[0].$1.$1][dpval[0].$1.$2];
  visit[si][sj] = false;
  return dp[si][sj];
}

int main() {
  UNSYNC; READTXT;
  INPUT2(N, M);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      INPUT(value[i][j]);
    }
  }

  for (int i = 1; i <= N; i++) {
    memset(dp, 0, sizeof(dp));
    memset(dp_pos, 0, sizeof(dp_pos));
    memset(visit, 0, sizeof(visit));
    DFS(i, 1);

    ans[dp_pos[i][1]]++;
  }
  for (int i = 1; i <= N; i++)
    PRINT(ans[i]);
  return 0;
}
*/