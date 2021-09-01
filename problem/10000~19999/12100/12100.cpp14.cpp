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

int N;
int tempMax[15] = {};
int field[20][20] = {};

int getMax(int f[20][20]) {
    int m = INT_MIN;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m = max(m, f[i][j]);
        }
    }
    return m;
}

bool isSame(int f[20][20], int ff[20][20]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (f[i][j] != ff[i][j]) return false;
        }
    }
    return true;
}

int dfs(int ff[20][20], int level) {
    int m = INT_MIN;

    for (int dir = 0; dir < 4; dir++) {
        int me = 0;
        int f[20][20];
        bool merged[25][25] = {};
        memcpy(f, ff, sizeof(f));

        if (dir == 0) {
            // UP
            for (int i = 1; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (f[i][j] == 0) continue;
                    me = max(me, f[i][j]);

                    for (int k = i - 1; k >= 0; k--) {
                        if (f[k][j] != 0) {
                            if (f[i][j] == f[k][j] && !merged[k][j]) {
                                f[k][j] *= 2;
                                f[i][j] = 0;
                                me = max(me, f[k][j]);
                                merged[k][j] = true;
                            }
                            else {
                                int t = f[i][j];
                                f[i][j] = 0;
                                f[k + 1][j] = t;
                            }
                            break;
                        }
                        else if (k == 0) {
                            f[k][j] = f[i][j];
                            f[i][j] = 0;
                        }
                    }
                }
            }

            if (isSame(f, ff) || me < tempMax[level]) {
                m = max(m, me);
                continue;
            }

            if (level < 5)
                m = max(m, dfs(f, level + 1));
            else {
                if (me > tempMax[level]) {
                    tempMax[level] = me;
                    for (int i = level - 1; i >= 1; i--) {
                        tempMax[i] = max(tempMax[i], tempMax[i + 1] / 2);
                    }
                }
                m = max(m, me);
            }
        }

        if (dir == 1) {
            // DOWN
            for (int i = N - 2; i >= 0; i--) {
                for (int j = 0; j < N; j++) {
                    if (f[i][j] == 0) continue;
                    me = max(me, f[i][j]);

                    for (int k = i + 1; k < N; k++) {
                        if (f[k][j] != 0) {
                            if (f[i][j] == f[k][j] && !merged[k][j]) {
                                f[k][j] *= 2;
                                f[i][j] = 0;
                                me = max(me, f[k][j]);
                                merged[k][j] = true;
                            }
                            else {
                                int t = f[i][j];
                                f[i][j] = 0;
                                f[k - 1][j] = t;
                            }
                            break;
                        }
                        else if (k == N - 1) {
                            f[k][j] = f[i][j];
                            f[i][j] = 0;
                        }
                    }
                }
            }

            if (isSame(f, ff) || me < tempMax[level]) {
                m = max(m, me);
                continue;
            }

            if (level < 5)
                m = max(m, dfs(f, level + 1));
            else {
                if (me > tempMax[level]) {
                    tempMax[level] = me;
                    for (int i = level - 1; i >= 1; i--) {
                        tempMax[i] = max(tempMax[i], tempMax[i + 1] / 2);
                    }
                }
                m = max(m, me);
            }
        }

        if (dir == 2) {
            // LEFT
            for (int i = 0; i < N; i++) {
                for (int j = 1; j < N; j++) {
                    if (f[i][j] == 0) continue;
                    me = max(me, f[i][j]);

                    for (int k = j - 1; k >= 0; k--) {
                        if (f[i][k] != 0) {
                            if (f[i][k] == f[i][j] && !merged[i][k]) {
                                f[i][k] *= 2;
                                f[i][j] = 0;
                                me = max(me, f[i][k]);
                                merged[i][k] = true;
                            }
                            else {
                                int t = f[i][j];
                                f[i][j] = 0;
                                f[i][k + 1] = t;
                            }
                            break;
                        }
                        else if (k == 0) {
                            f[i][k] = f[i][j];
                            f[i][j] = 0;
                        }
                    }
                }
            }

            if (isSame(f, ff) || me < tempMax[level]) {
                m = max(m, me);
                continue;
            }

            if (level < 5)
                m = max(m, dfs(f, level + 1));
            else {
                if (me > tempMax[level]) {
                    tempMax[level] = me;
                    for (int i = level - 1; i >= 1; i--) {
                        tempMax[i] = max(tempMax[i], tempMax[i + 1] / 2);
                    }
                }
                m = max(m, me);
            }
        }

        if (dir == 3) {
            // RIGHT
            for (int i = 0; i < N; i++) {
                for (int j = N - 2; j >= 0; j--) {
                    if (f[i][j] == 0) continue;
                    me = max(me, f[i][j]);

                    for (int k = j + 1; k < N; k++) {
                        if (f[i][k] != 0) {
                            if (f[i][k] == f[i][j] && !merged[i][k]) {
                                f[i][k] *= 2;
                                f[i][j] = 0;
                                me = max(me, f[i][k]);
                                merged[i][k] = true;
                            }
                            else {
                                int t = f[i][j];
                                f[i][j] = 0;
                                f[i][k - 1] = t;
                            }
                            break;
                        }
                        else if (k == N - 1) {
                            f[i][k] = f[i][j];
                            f[i][j] = 0;
                        }
                    }
                }
            }

            if (isSame(f, ff) || me < tempMax[level]) {
                m = max(m, me);
                continue;
            }

            if (level < 5)
                m = max(m, dfs(f, level + 1));
            else {
                if (me > tempMax[level]) {
                    tempMax[level] = me;
                    for (int i = level - 1; i >= 1; i--) {
                        tempMax[i] = max(tempMax[i], tempMax[i + 1] / 2);
                    }
                }
                m = max(m, me);
            }
        }
    }

    return m;
}

int main() {
    UNSYNC; READTXT;
    INPUT(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> field[i][j];
        }
    }

    if (N == 1) {
        cout << field[0][0];
        return 0;
    }

    PRINT(dfs(field, 1));
}