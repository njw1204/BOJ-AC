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
#define UNSYNC ios_base::sync_with_stdio(false);cin.tie(nullptr)
#endif
#define TXTPATH "_input.txt"
inline ull GCD(ull a, ull b) { while (b != 0) { ull t = a % b; a = b; b = t; } return a; }
inline ull LCM(ull a, ull b) { return a * b / GCD(a, b); }
inline ull POW(ull a, ull b, ull m = ULLONG_MAX) { ull r = 1;	while (b) { if (b & 1) r = r * a % m; b >>= 1; a = a * a % m; } return r; }

int N, K;
int field[35][35];
map<pi, int> nowCnt;

int Count(pi pos) {
  int ans = 0;
  if (pos.$2 == 0) {
    for (int j = 1; j <= N; j++)
      if (field[pos.$1][j] == K) ans++;
  }
  else {
    for (int i = 1; i <= N; i++)
      if (field[i][pos.$2] == K) ans++;
  }
  return ans;
}

void Reverse(pi pos) {
  if (pos.$2 == 0) {
    for (int j = 1; j <= N; j++)
      field[pos.$1][j] = K;
  }
  else {
    for (int i = 1; i <= N; i++)
      field[i][pos.$2] = K;
  }
}

int main() {
  UNSYNC; READTXT;
  INPUT2(N, K);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      cin >> field[i][j];

  while (1) {
    set<pair<int, pi>, greater<>> Q;

    for (int i = 1; i <= N; i++) {
      nowCnt[{i, 0}] = Count({i,0});
      if (nowCnt[{i, 0}] != N && nowCnt[{i, 0}] > N / 2) Q.insert({nowCnt[{i, 0}],{i,0}});
      nowCnt[{0, i}] = Count({0,i});
      if (nowCnt[{0, i}] != N && nowCnt[{0, i}] > N / 2) Q.insert({nowCnt[{0, i}],{0,i}});
    }

    if (Q.empty()) break;
    auto i = *Q.begin();
    Reverse(i.$2);
  }

  int cnt = 0;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      cnt += (field[i][j] == K);

  if (cnt == N * N) cout << 1;
  else cout << 0;
  return 0;
}