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

int N;
int asdf[100005];
int result[100005];
int nowCnt[100005];
vector<pair<pi, int>> query;
int numCntOfCnt[100005];
set<int, greater<int>> canCnt;

int main() {
    UNSYNC; READTXT;
    cin >> N;

    REP(i, N) {
        DINPUT(x);
        asdf[i] = x;
    }

    TESTCASE(T) {
        DINPUT2(a, b);
        query.pb({{a - 1, b - 1}, T});
    }

    sort(ALL(query), [](const auto& aa, const auto& bb) {
        pi a = aa.$1, b = bb.$1;

        a.$1 /= sqrt(N);
        b.$1 /= sqrt(N);

        if (a.$1 < b.$1) return true;
        else if (a.$1 > b.$1) return false;
        else return (a.$2 < b.$2);
    });

    int left = 0, right = 0;
    nowCnt[asdf[0]]++;
    numCntOfCnt[1]++;
    canCnt.insert(1);

    for (auto xx : query) {
        pi x = xx.$1;

        if (x.$1 >= right || x.$2 <= left) {
            INIT(nowCnt);
            INIT(numCntOfCnt);
            canCnt.clear();

            for (int i = x.$1; i <= x.$2; i++) {
                if (nowCnt[asdf[i]]) {
                    numCntOfCnt[nowCnt[asdf[i]]]--;
                    if (numCntOfCnt[nowCnt[asdf[i]]] == 0) {
                        canCnt.erase(nowCnt[asdf[i]]);
                    }
                }

                nowCnt[asdf[i]]++;
                numCntOfCnt[nowCnt[asdf[i]]]++;
                if (numCntOfCnt[nowCnt[asdf[i]]] == 1) {
                    canCnt.insert(nowCnt[asdf[i]]);
                }
            }
        }
        else if (x.$1 <= left && x.$2 >= right) {
            for (int i = x.$1; i < left; i++) {
                if (nowCnt[asdf[i]]) {
                    numCntOfCnt[nowCnt[asdf[i]]]--;
                    if (numCntOfCnt[nowCnt[asdf[i]]] == 0) {
                        canCnt.erase(nowCnt[asdf[i]]);
                    }
                }

                nowCnt[asdf[i]]++;
                numCntOfCnt[nowCnt[asdf[i]]]++;
                if (numCntOfCnt[nowCnt[asdf[i]]] == 1) {
                    canCnt.insert(nowCnt[asdf[i]]);
                }
            }
            for (int i = right + 1; i <= x.$2; i++) {
                if (nowCnt[asdf[i]]) {
                    numCntOfCnt[nowCnt[asdf[i]]]--;
                    if (numCntOfCnt[nowCnt[asdf[i]]] == 0) {
                        canCnt.erase(nowCnt[asdf[i]]);
                    }
                }

                nowCnt[asdf[i]]++;
                numCntOfCnt[nowCnt[asdf[i]]]++;
                if (numCntOfCnt[nowCnt[asdf[i]]] == 1) {
                    canCnt.insert(nowCnt[asdf[i]]);
                }
            }
        }
        else if (x.$1 <= left && x.$2 <= right) {
            for (int i = x.$1; i < left; i++) {
                if (nowCnt[asdf[i]]) {
                    numCntOfCnt[nowCnt[asdf[i]]]--;
                    if (numCntOfCnt[nowCnt[asdf[i]]] == 0) {
                        canCnt.erase(nowCnt[asdf[i]]);
                    }
                }

                nowCnt[asdf[i]]++;
                numCntOfCnt[nowCnt[asdf[i]]]++;
                if (numCntOfCnt[nowCnt[asdf[i]]] == 1) {
                    canCnt.insert(nowCnt[asdf[i]]);
                }
            }
            for (int i = right; i > x.$2; i--) {
                numCntOfCnt[nowCnt[asdf[i]]]--;
                if (numCntOfCnt[nowCnt[asdf[i]]] == 0) {
                    canCnt.erase(nowCnt[asdf[i]]);
                }

                nowCnt[asdf[i]]--;
                if (nowCnt[asdf[i]]) {
                    numCntOfCnt[nowCnt[asdf[i]]]++;
                    if (numCntOfCnt[nowCnt[asdf[i]]] == 1) {
                        canCnt.insert(nowCnt[asdf[i]]);
                    }
                }
            }
        }
        else if (x.$1 >= left && x.$2 <= right) {
            for (int i = left; i < x.$1; i++) {
                numCntOfCnt[nowCnt[asdf[i]]]--;
                if (numCntOfCnt[nowCnt[asdf[i]]] == 0) {
                    canCnt.erase(nowCnt[asdf[i]]);
                }

                nowCnt[asdf[i]]--;
                if (nowCnt[asdf[i]]) {
                    numCntOfCnt[nowCnt[asdf[i]]]++;
                    if (numCntOfCnt[nowCnt[asdf[i]]] == 1) {
                        canCnt.insert(nowCnt[asdf[i]]);
                    }
                }
            }
            for (int i = right; i > x.$2; i--) {
                numCntOfCnt[nowCnt[asdf[i]]]--;
                if (numCntOfCnt[nowCnt[asdf[i]]] == 0) {
                    canCnt.erase(nowCnt[asdf[i]]);
                }

                nowCnt[asdf[i]]--;
                if (nowCnt[asdf[i]]) {
                    numCntOfCnt[nowCnt[asdf[i]]]++;
                    if (numCntOfCnt[nowCnt[asdf[i]]] == 1) {
                        canCnt.insert(nowCnt[asdf[i]]);
                    }
                }
            }
        }
        else {
            for (int i = left; i < x.$1; i++) {
                numCntOfCnt[nowCnt[asdf[i]]]--;
                if (numCntOfCnt[nowCnt[asdf[i]]] == 0) {
                    canCnt.erase(nowCnt[asdf[i]]);
                }

                nowCnt[asdf[i]]--;
                if (nowCnt[asdf[i]]) {
                    numCntOfCnt[nowCnt[asdf[i]]]++;
                    if (numCntOfCnt[nowCnt[asdf[i]]] == 1) {
                        canCnt.insert(nowCnt[asdf[i]]);
                    }
                }
            }
            for (int i = right + 1; i <= x.$2; i++) {
                if (nowCnt[asdf[i]]) {
                    numCntOfCnt[nowCnt[asdf[i]]]--;
                    if (numCntOfCnt[nowCnt[asdf[i]]] == 0) {
                        canCnt.erase(nowCnt[asdf[i]]);
                    }
                }

                nowCnt[asdf[i]]++;
                numCntOfCnt[nowCnt[asdf[i]]]++;
                if (numCntOfCnt[nowCnt[asdf[i]]] == 1) {
                    canCnt.insert(nowCnt[asdf[i]]);
                }
            }
        }

        left = x.$1;
        right = x.$2;
        result[xx.$2] = *canCnt.begin();
    }

    for (int i = 0; i < query.size(); i++) {
        PRINT(result[i + 1]);
    }

    return 0;
}