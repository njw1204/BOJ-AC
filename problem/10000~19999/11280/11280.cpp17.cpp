#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
#include <complex>
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

int N, M;
vector<int> link[10005][2];
vector<int> rlink[10005][2];
bool visited[10005][2];
bool rvisited[10005][2];
int sccNum[10005][2];
stack<int> dfsStack;

const int NODE_TYPE_TRUTHY = 0;
const int NODE_TYPE_FALSHY = 1;

void dfs(int root) {
    visited[abs(root)][root > 0 ? NODE_TYPE_TRUTHY : NODE_TYPE_FALSHY] = true;
    for (auto node : link[abs(root)][root > 0 ? NODE_TYPE_TRUTHY : NODE_TYPE_FALSHY]) {
        if (!visited[abs(node)][node > 0 ? NODE_TYPE_TRUTHY : NODE_TYPE_FALSHY]) {
            dfs(node);
        }
    }

    dfsStack.push(root);
}

void rdfs(int root, int nowSccNum) {
    sccNum[abs(root)][root > 0 ? NODE_TYPE_TRUTHY : NODE_TYPE_FALSHY] = nowSccNum;
    rvisited[abs(root)][root > 0 ? NODE_TYPE_TRUTHY : NODE_TYPE_FALSHY] = true;
    for (auto node : rlink[abs(root)][root > 0 ? NODE_TYPE_TRUTHY : NODE_TYPE_FALSHY]) {
        if (!rvisited[abs(node)][node > 0 ? NODE_TYPE_TRUTHY : NODE_TYPE_FALSHY]) {
            rdfs(node, nowSccNum);
        }
    }
}

int main() {
    UNSYNC;

    INPUT2(N, M);
    REP(i, M) {
        DINPUT2(a, b);
        link[abs(a)][a > 0 ? NODE_TYPE_FALSHY : NODE_TYPE_TRUTHY].pb(b);
        link[abs(b)][b > 0 ? NODE_TYPE_FALSHY : NODE_TYPE_TRUTHY].pb(a);
        rlink[abs(b)][b > 0 ? NODE_TYPE_TRUTHY : NODE_TYPE_FALSHY].pb(-a);
        rlink[abs(a)][a > 0 ? NODE_TYPE_TRUTHY : NODE_TYPE_FALSHY].pb(-b);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 1; j++) {
            int root = i * (j == 0 ? 1 : -1);
            if (!visited[abs(root)][root > 0 ? NODE_TYPE_TRUTHY : NODE_TYPE_FALSHY]) {
                dfs(root);
            }
        }
    }

    for (int i = 1; !dfsStack.empty(); i++) {
        int root = dfsStack.top();
        if (!rvisited[abs(root)][root > 0 ? NODE_TYPE_TRUTHY : NODE_TYPE_FALSHY]) {
            rdfs(root, i);
        }
        dfsStack.pop();
    }

    for (int i = 1; i <= N; i++) {
        if (sccNum[i][0] == sccNum[i][1] && sccNum[i][0] != 0) {
            PRINT(0);
            return 0;
        }
    }

    PRINT(1);
    return 0;
}