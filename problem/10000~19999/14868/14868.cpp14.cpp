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

int N, K;
int parent[1000005];
int visit[2005][2005];
int field[2005][2005];
int unionCnt;

int Find(int a) {
    if (parent[a] != -1) return parent[a] = Find(parent[a]);
    else return a;
}

void Union(int a, int b) {
    int ppa = Find(a), ppb = Find(b);
    if (ppa == ppb) return;
    parent[ppb] = ppa;
    unionCnt++;
}

int main() {
    UNSYNC; READTXT;
    INPUT2(N, K);
    memset(parent, -1, sizeof(parent));
    queue<pair<int, int>> Q;

    for (int i = 1; i <= K; i++) {
        DINPUT2(x, y);
        field[x][y] = i;
        Q.push({x,y});
        visit[x][y] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (field[i][j]) {
                if (field[i + 1][j])
                    Union(field[i][j], field[i + 1][j]);
                if (field[i - 1][j])
                    Union(field[i][j], field[i - 1][j]);
                if (field[i][j + 1])
                    Union(field[i][j], field[i][j + 1]);
                if (field[i][j - 1])
                    Union(field[i][j], field[i][j - 1]);
            }
        }
    }

    int year = 0;

    while (unionCnt < K - 1 && !Q.empty()) {
        year++;
        while (!Q.empty()) {
            int si, sj;
            tie(si, sj) = Q.front();

            if (visit[si][sj] > year) break;
            Q.pop();

            pair<int, int> dx[4] = {{1,0},{-1,0},{0,1},{0,-1}};
            for (auto d : dx) {
                int ni, nj;
                tie(ni, nj) = make_pair(si + d.$1, sj + d.$2);

                if (!visit[ni][nj] && 1 <= ni && ni <= N && 1 <= nj && nj <= N) {
                    field[ni][nj] = field[si][sj];
                    visit[ni][nj] = visit[si][sj] + 1;
                    Q.push({ni,nj});

                    if (field[ni + 1][nj])
                        Union(field[ni][nj], field[ni + 1][nj]);
                    if (field[ni - 1][nj])
                        Union(field[ni][nj], field[ni - 1][nj]);
                    if (field[ni][nj + 1])
                        Union(field[ni][nj], field[ni][nj + 1]);
                    if (field[ni][nj - 1])
                        Union(field[ni][nj], field[ni][nj - 1]);
                }
            }
        }
    }

    return cout << year, 0;
}