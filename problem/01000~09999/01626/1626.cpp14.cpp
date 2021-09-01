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

int V, E;
vector<pi> link[100005];

int parent[100005][31];
int lcaKeyValue[100005][31];
int lcaKeyValue2[100005][31];
int height[100005];
bool visit[100005];
vector<pi> linkTree[100005];

int disjointSet[100005];
vector<pair<pi,int>> minSpanningTreeLink;
vector<pair<pi, int>> notIncludedLink;
ll minSpanningTreeValue;

int Find(int i) {
    if (disjointSet[i])
        return (disjointSet[i] = Find(disjointSet[i]));
    else
        return i;
}

void Union(int i, int j) {
    int si = Find(i), sj = Find(j);
    if (si == sj) return;
    disjointSet[si] = sj;
}

void DFS(int start) {
    visit[start] = true;
    for (auto i : linkTree[start]) {
        if (!visit[i.$1]) {
            parent[i.$1][0] = start;
            height[i.$1] = height[start] + 1;
            lcaKeyValue[i.$1][0] = i.$2;
            lcaKeyValue2[i.$1][0] = i.$2;
            DFS(i.$1);
        }
    }
}

pi LCA(int a, int b) {
    set<int, greater<int>> answerSet;

    if (height[a] > height[b]) swap(a, b);
    for (int i = 30; i >= 0; i--) {
        if (height[b] - height[a] >= 1 << i) {
            answerSet.insert(lcaKeyValue[b][i]);
            answerSet.insert(lcaKeyValue2[b][i]);
            b = parent[b][i];
        }
    }
    if (a == b) {
        int fi = *answerSet.begin(), se = *answerSet.begin();
        answerSet.erase(*answerSet.begin());
        if (!answerSet.empty()) se = *answerSet.begin();
        return {fi,se};
    }

    for (int i = 30; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            answerSet.insert(lcaKeyValue[a][i]);
            answerSet.insert(lcaKeyValue2[a][i]);
            answerSet.insert(lcaKeyValue[b][i]);
            answerSet.insert(lcaKeyValue2[b][i]);
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    answerSet.insert(lcaKeyValue[a][0]);
    answerSet.insert(lcaKeyValue2[a][0]);
    answerSet.insert(lcaKeyValue[b][0]);
    answerSet.insert(lcaKeyValue2[b][0]);

    int fi = *answerSet.begin(), se = *answerSet.begin();
    answerSet.erase(*answerSet.begin());
    if (!answerSet.empty()) se = *answerSet.begin();
    return {fi,se};
}

int main() {
    UNSYNC; READTXT;
    INPUT2(V, E);
    if (V == 1) return cout << -1, 0;

    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> pq;

    REP(i, E) {
        DINPUT3(a, b, w);
        if (a == b) continue;

        link[a].pb({b,w});
        link[b].pb({a,w});
        pq.push({w,{a,b}});
    }

    while (!pq.empty()) {
        pair<int, pi> x = pq.top(); pq.pop();
        if (Find(x.$2.$1) != Find(x.$2.$2)) {
            Union(x.$2.$1, x.$2.$2);
            minSpanningTreeLink.pb({x.$2, x.$1});
            linkTree[x.$2.$1].pb({x.$2.$2, x.$1});
            linkTree[x.$2.$2].pb({x.$2.$1, x.$1});
            minSpanningTreeValue += x.$1;
        }
        else {
            notIncludedLink.pb({x.$2, x.$1});
        }
    }

    if (minSpanningTreeLink.size() < V - 1) {
        return cout << -1, 0;
    }

    DFS(1);
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= V; j++) {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
            lcaKeyValue[j][i] = max(lcaKeyValue[j][i - 1], lcaKeyValue[parent[j][i - 1]][i - 1]);

            set<int, greater<int>> tmp;
            tmp.insert(lcaKeyValue[j][i - 1]);
            tmp.insert(lcaKeyValue[parent[j][i - 1]][i - 1]);
            tmp.insert(lcaKeyValue2[j][i - 1]);
            tmp.insert(lcaKeyValue2[parent[j][i - 1]][i - 1]);

            if (tmp.size() == 1) {
                lcaKeyValue2[j][i] = *tmp.begin();
            }
            else {
                tmp.erase(*tmp.begin());
                lcaKeyValue2[j][i] = *tmp.begin();
            }
        }
    }

    ll ans = LLONG_MAX;
    for (auto i : notIncludedLink) {
        pi lcaResult = LCA(i.$1.$1, i.$1.$2);
        ll tmpAns = minSpanningTreeValue + i.$2;

        if (tmpAns - lcaResult.$1 > minSpanningTreeValue) {
            ans = min(ans, tmpAns - lcaResult.$1);
        }
        else if (tmpAns - lcaResult.$2 > minSpanningTreeValue) {
            ans = min(ans, tmpAns - lcaResult.$2);
        }
    }

    if (ans == minSpanningTreeValue || ans == LLONG_MAX) cout << -1;
    else cout << ans;
}