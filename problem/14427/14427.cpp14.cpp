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


int N;
int tree[500000];
int arr[500000];
int treeSize;

void Init(int dataLen) {
  for (treeSize = 1; treeSize < dataLen * 2; treeSize *= 2);
  for (int i = 0; i <= treeSize; i++) tree[i] = INT_MAX;
}

int Check(int L, int R, int node = 1, int nodeL = 0, int nodeR = treeSize / 2 - 1) {
  if (nodeL > R || nodeR < L) return INT_MAX;
  if (nodeL >= L && nodeR <= R) return tree[node];
  int mid = (nodeL + nodeR) / 2;

  int a = Check(L, R, node * 2, nodeL, mid), b = Check(L, R, node * 2 + 1, mid + 1, nodeR);
  
  if (a == INT_MAX) return b;
  else if (b == INT_MAX) return a;
  else if (arr[a] < arr[b]) return a;
  else if (arr[b] < arr[a]) return b;
  else return min(a, b);
}

void Update(int idx, int val) {
  arr[idx] = val;
  tree[idx + treeSize / 2] = idx;
  idx += treeSize / 2;

  while (idx > 1) {
    idx /= 2;
    if (tree[idx * 2] == INT_MAX)
      tree[idx] = tree[idx * 2 + 1];
    else if (tree[idx * 2 + 1] == INT_MAX)
      tree[idx] = tree[idx * 2];
    else if (arr[tree[idx * 2]] < arr[tree[idx * 2 + 1]])
      tree[idx] = tree[idx * 2];
    else if ((arr[tree[idx * 2 + 1]] < arr[tree[idx * 2]]))
      tree[idx] = tree[idx * 2 + 1];
    else
      tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
  }
}

int main() {
  UNSYNC; READTXT;

  cin >> N;
  Init(N);

  REP(i, N) {
    DINPUT(x);
    Update(i, x);
  }

  TESTCASE(M) {
    DINPUT(o);
    if (o == 1) {
      DINPUT2(i, j);
      Update(i - 1, j);
    }
    else {
      cout << Check(0, N - 1) + 1 << endl;
    }
  }

  return 0;
}