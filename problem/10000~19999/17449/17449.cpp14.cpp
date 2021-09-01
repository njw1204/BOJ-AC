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
#define PRINT(cout_x) cout<<(cout_x)<<'\n'
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

int R, N;
vector<int> arr;
int basis[200005];

int tree[800005];
int treeSize;

void Init(int dataLen) {
    for (treeSize = 1; treeSize < dataLen * 2; treeSize *= 2);
    for (int i = 1; i <= treeSize; i++) tree[i] = INF;
}

int Check(int L, int R, int node = 1, int nodeL = 0, int nodeR = treeSize / 2 - 1) {
    if (nodeL > R || nodeR < L) return INF;
    if (nodeL >= L && nodeR <= R) return tree[node];
    int mid = (nodeL + nodeR) / 2;
    return min(Check(L, R, node * 2, nodeL, mid), Check(L, R, node * 2 + 1, mid + 1, nodeR));
}

void Update(int idx, int val) {
    idx += treeSize / 2;
    tree[idx] = val;
    while (idx > 1) {
        idx /= 2;
        tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
    }
}

int main() {
    UNSYNC; READTXT;
    INPUT2(R, N);
    arr.pb(0);

    REP(i, N) {
        DINPUT(x);
        arr.pb(x);
    }

    Init(200001);
    Update(arr[N], arr[N]);

    for (int i = N - 1; i >= 1; i--) {
        int c = Check(arr[i] + 1, 200000);
        if (c != INF) {
            basis[i] = c;
        }
        Update(arr[i], arr[i]);
    }

    int best = R, worst = R;
    int bestSame = 0;

    for (int i = 1; i <= N; i++) {
        if (arr[i] < best) {
            best++;
        }

        if (arr[i] < worst) {
            worst++;
        }

        if (arr[i] == best) {
            bestSame++;
        }

        if (arr[i] == worst) {
            worst++;
        }

        if (arr[i] > best) {
            if (arr[i] <= best + bestSame) {
                int need = best + bestSame - arr[i];
                best = arr[i];
                bestSame = need + 1;
            }
        }
    }

    return cout << best << ' ' << worst, 0;
}