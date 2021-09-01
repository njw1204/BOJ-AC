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
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <bitset>
#include <limits>
#include <numeric>
#include <iomanip>
#include <random>
#include <complex>
#include <valarray>
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

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int op = a.first * b.second + b.first * c.second + c.first * a.second;
    op -= (a.second * b.first + b.second * c.first + c.second * a.first);
    if (op > 0) return 1;
    else if (op == 0) return 0;
    else return -1;
}

int isIntersect(pair<pair<int, int>, pair<int, int>> x, pair<pair<int, int>, pair<int, int>> y) {
    pair<int, int> a = x.first;
    pair<int, int> b = x.second;
    pair<int, int> c = y.first;
    pair<int, int> d = y.second;
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}

const int MAX = 1000005;

// data structures used to implement Kosaraju's 
// Algorithm. Please refer 
// http://www.geeksforgeeks.org/strongly-connected-components/ 
vector<int> adj[MAX];
vector<int> adjInv[MAX];
bool visited[MAX];
bool visitedInv[MAX];
stack<int> s;

// this array will store the SCC that the 
// particular node belongs to 
int scc[MAX];

// counter maintains the number of the SCC 
int counter = 1;

bool satResult[MAX];

// adds edges to form the original graph 
void addEdges(int a, int b)
{
    adj[a].push_back(b);
}

// add edges to form the inverse graph 
void addEdgesInverse(int a, int b)
{
    adjInv[b].push_back(a);
}

// for STEP 1 of Kosaraju's Algorithm 
void dfsFirst(int u)
{
    if (visited[u])
        return;

    visited[u] = 1;

    for (int i = 0; i < adj[u].size(); i++)
        dfsFirst(adj[u][i]);

    s.push(u);
}

// for STEP 2 of Kosaraju's Algorithm 
void dfsSecond(int u)
{
    if (visitedInv[u])
        return;

    visitedInv[u] = 1;

    for (int i = 0; i < adjInv[u].size(); i++)
        dfsSecond(adjInv[u][i]);

    scc[u] = counter;
}

// function to check 2-Satisfiability 
bool is2Satisfiable(int n, int m, const vector<int>& a, const vector<int>& b) {
    // adding edges to the graph 
    for (int i = 0; i < m; i++)
    {
        // variable x is mapped to x 
        // variable -x is mapped to n+x = n-(-x) 

        // for a[i] or b[i], addEdges -a[i] -> b[i] 
        // AND -b[i] -> a[i] 
        if (a[i] > 0 && b[i] > 0)
        {
            addEdges(a[i] + n, b[i]);
            addEdgesInverse(a[i] + n, b[i]);
            addEdges(b[i] + n, a[i]);
            addEdgesInverse(b[i] + n, a[i]);
        }

        else if (a[i] > 0 && b[i] < 0)
        {
            addEdges(a[i] + n, n - b[i]);
            addEdgesInverse(a[i] + n, n - b[i]);
            addEdges(-b[i], a[i]);
            addEdgesInverse(-b[i], a[i]);
        }

        else if (a[i] < 0 && b[i]>0)
        {
            addEdges(-a[i], b[i]);
            addEdgesInverse(-a[i], b[i]);
            addEdges(b[i] + n, n - a[i]);
            addEdgesInverse(b[i] + n, n - a[i]);
        }

        else
        {
            addEdges(-a[i], n - b[i]);
            addEdgesInverse(-a[i], n - b[i]);
            addEdges(-b[i], n - a[i]);
            addEdgesInverse(-b[i], n - a[i]);
        }
    }

    // STEP 1 of Kosaraju's Algorithm which 
    // traverses the original graph 
    for (int i = 1; i <= 2 * n; i++)
        if (!visited[i])
            dfsFirst(i);

    // STEP 2 pf Kosaraju's Algorithm which 
    // traverses the inverse graph. After this, 
    // array scc[] stores the corresponding value 
    while (!s.empty())
    {
        int n = s.top();
        s.pop();

        if (!visitedInv[n])
        {
            dfsSecond(n);
            counter++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        // for any 2 vairable x and -x lie in 
        // same SCC 
        if (scc[i] == scc[i + n]) {
            return false;
        }
        else {
            if (scc[i] == 0) {
                satResult[i] = true;
            }
            else if (scc[i + n] == 0) {
                satResult[i] = false;
            }
            else if (scc[i + n] < scc[i]) {
                satResult[i] = true;
            }
            else {
                satResult[i] = false;
            }
        }
    }

    // no such variables x and -x exist which lie 
    // in same SCC
    return true;
}

int main() {
    UNSYNC; READTXT;
    DINPUT(N);

    vector<ppi> dots;
    vector<int> a, b;

    int n = N * 3, m = 0;

    for (int p = 0; p < N; p++) {
        for (int i = 0; i < 3; i++) {
            DINPUT4(a, b, c, d);
            dots.pb({{a,b},{c,d}});
        }

        a.pb(p * 3 + 1);
        b.pb(p * 3 + 2);
        a.pb(p * 3 + 1);
        b.pb(p * 3 + 3);
        a.pb(p * 3 + 2);
        b.pb(p * 3 + 3);
        m += 3;
    }

    for (int i = 0; i < dots.size(); i++) {
        for (int j = i + 1; j < dots.size(); j++) {
            if (isIntersect(dots[i], dots[j])) {
                int ix = i + 1, jx = j + 1;
                a.pb(-ix);
                b.pb(-jx);
                m++;
            }
        }
    }

    bool sat = is2Satisfiable(n, m, a, b);
    if (sat) {
        int cnt = 0;
        vector<int> printAns;
        for (int i = 1; i <= N * 3; i++) {
            if (!satResult[i]) {
                cnt++;
                printAns.pb(i);
            }
        }
        PRINT(cnt);
        for (int i : printAns) {
            cout << i << ' ';
        }
    }
    else {
        cout << -1;
    }
}