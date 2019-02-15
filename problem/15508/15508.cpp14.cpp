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
#include <regex>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
typedef unsigned int ui;
typedef long long int ll;
typedef unsigned long long int ull;
#define $1 first
#define $2 second
#define pb push_back
#define INF 0x5A5B5C5D
#define INF2 0x77777777
#define INT_MAX 0x7FFFFFFF
#define UINT_MAX (ui)0xFFFFFFFF
#define LL_MAX (ll)0x7FFFFFFFFFFFFFFF
#define ULL_MAX (ull)0xFFFFFFFFFFFFFFFF
#define PI 3.1415926535897932
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define REP(i,n) for(ull i=0;i<(n);i++)
#define ALL(list) (list).begin(),(list).end()
#define PRESENT(list,x) (find(ALL(list),x)!=(list).end())
#define INPUT(cin_a) cin>>(cin_a)
#define INPUT2(cin_a,cin_b) cin>>(cin_a)>>(cin_b)
#define INPUT3(cin_a,cin_b,cin_c) cin>>(cin_a)>>(cin_b)>>(cin_c)
#define DINPUT(int_a) int (int_a);scanf("%d",&(int_a))
#define DINPUT2(int_a,int_b) int (int_a),(int_b);scanf("%d%d",&(int_a),&(int_b))
#define DINPUT3(int_a,int_b,int_c) int (int_a),(int_b),(int_c);scanf("%d%d%d",&(int_a),&(int_b),&(int_c))
#define TESTCASE(T) DINPUT(i_i__ai);for((T)=1;(T)<=i_i__ai;(T)++)
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
#else
#define READTXT
#endif
#define TXTPATH "_input.txt"
inline ull GCD(ull a, ull b) { while (b != 0) { ull t = a % b; a = b; b = t; } return a; }
inline ull LCM(ull a, ull b) { return a * b / GCD(a, b); }

ull pos_key[1001];
ull pos[1001];
ull preSum[1001];
ull pos_cnt[1001];

int main() {
  READTXT;
  DINPUT3(n, m, k);
  if (n == 1 || n <= k) {
    puts("SAFE");
    return 0;
  }
  int capa_max = MAX(k, n - k);
  int capa_min = MIN(k, n - k);
  int new_pos = 1;
  int max_cnt = 0;

  REP(i, 1001) pos_key[i] = i;

  REP(i, m) {
    DINPUT2(a, b);
    if (a > b) swap(a, b);
    if (a == b) continue;
    if (pos[a] && pos[b]) {
      if (pos_key[pos[a]] == pos_key[pos[b]]) continue;
      pos_cnt[pos_key[pos[a]]] += pos_cnt[pos_key[pos[b]]];
      pos_cnt[pos_key[pos[b]]] = pos_cnt[pos_key[pos[a]]];
      int temp = pos_key[pos[b]];
      for (int i = 1; i <= n; i++) {
        if (pos_key[i] == temp) pos_key[i] = pos_key[pos[a]];
      }
    } else if (pos[a]) {
      pos[b] = pos[a];
      pos_cnt[pos_key[pos[a]]]++;
    } else if (pos[b]) {
      pos[a] = pos[b];
      pos_cnt[pos_key[pos[a]]]++;
    } else {
      pos[a] = new_pos;
      pos[b] = new_pos;
      pos_cnt[new_pos] = 2;
      new_pos++;
    }
  }

  int tt = 0;
  for (int i = 1; i <= n; i++) {
    if (pos_key[i] == i && pos_cnt[i]) {
      tt++;
      preSum[tt] = preSum[tt - 1] + pos_cnt[pos_key[i]];
    }
  }

  for (ull i = preSum[tt] + 1, j = tt + 1; i <= n; i++, j++) {
    preSum[j] = i;
    tt++;
  }

  for (int i = 0; i <= tt - 1; i++) {
    for (int j = i + 1; j <= tt; j++) {
      ull tempSum = preSum[j] - preSum[i];
      ull tempSum2 = n - tempSum;
      if (MAX(tempSum, tempSum2) == capa_max) {
        puts("SAFE");
        return 0;
      }
    }
  }

  puts("DOOMED");
  return 0;
}