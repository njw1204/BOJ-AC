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

int conn[1005];
bool visit[1005];
vector<int> originArr[2];
vector<int> arr[1001];
bool ok[1001];

bool DFS(int start) {
    visit[start] = true;
    for (auto i : arr[start]) {
        if (conn[i] == 0 || (!visit[conn[i]] && DFS(conn[i]))) {
            conn[i] = start;
            return true;
        }
    }
    return false;
}

bool isPrime(int val) {
    for (int i = 2; i * i <= val; i++) {
        if (val % i == 0) return false;
    }
    return true;
}

int main() {
    UNSYNC; READTXT;
    DINPUT(N);

    int target = 0;
    REP(i, N) {
        DINPUT(x);
        if (i == 0) {
            if (x % 2 == 0) target = 0;
            else target = 1;
        }
        originArr[(x + target) % 2].pb(x);
    }

    if (originArr[0].size() != originArr[1].size()) {
        return cout << -1, 0;
    }

    for (int i = 0; i < originArr[0].size(); i++) {
        ok[originArr[0][i]] = true;
        for (int j = 0; j < originArr[1].size(); j++) {
            if (isPrime(originArr[0][i] + originArr[1][j])) {
                arr[originArr[0][i]].pb(originArr[1][j]);
            }
        }

        if (arr[originArr[0][i]].empty()) {
            return cout << -1, 0;
        }
    }

    vector<int> ans;
    vector<int> tempLinkForFirst = arr[originArr[0][0]];

    for (int i = 0; i < tempLinkForFirst.size(); i++) {
        bool succ = true;

        arr[originArr[0][0]].clear();
        arr[originArr[0][0]].pb(tempLinkForFirst[i]);
        INIT(conn);

        for (int node : originArr[0]) {
            INIT(visit);
            if (!DFS(node)) {
                succ = false;
                break;
            }
        }

        if (!succ) continue;
        ans.pb(tempLinkForFirst[i]);
    }

    if (!ans.empty()) {
        sort(ALL(ans));
        for (int i : ans) {
            cout << i << ' ';
        }
    }
    else {
        cout << -1;
    }

    return 0;
}