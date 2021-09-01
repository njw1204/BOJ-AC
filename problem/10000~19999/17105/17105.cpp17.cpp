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

const long double PI = 3.1415926535897932;
typedef complex<double> base;

void fft(vector<base> &a, bool inv) {
    int n = (int)a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) swap(a[i], a[j]);
    }
    for (int s = 2; s <= n; s *= 2) {
        vector<base> w(s / 2);
        for (int i = 0; i < s / 2; i++) {
            double t = 2 * PI * i / s * (inv ? -1 : 1);
            w[i] = base(cos(t), sin(t));
        }
        for (int i = 0; i < n; i += s) {
            for (int j = 0; j < s / 2; j++) {
                base tmp = a[i + j + s / 2] * w[j];
                a[i + j + s / 2] = a[i + j] - tmp;
                a[i + j] += tmp;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
}

void multiply(vector<base> &a, vector<base> &b) {
    int n = (int)max(a.size(), b.size());
    int i = 0;
    while ((1 << i) < (n << 1)) i++;
    n = 1 << i;
    a.resize(n);
    b.resize(n);
    fft(a, false);
    fft(b, false);
    for (int i = 0; i < n; i++) {
        a[i] *= b[i];
    }
    fft(a, true);
}

bool isSosu[1000005];
vector<base> a, b, almost_ans;
vector<base> c, backup_a, backup_a_2;

int main() {
    UNSYNC; READTXT;

    FILL(isSosu, true);
    for (int i = 2; i * i <= 1000000; i++) {
        if (!isSosu[i]) continue;
        for (int j = i * i; j <= 1000000; j += i) {
            isSosu[j] = false;
        }
    }

    isSosu[0] = false;
    isSosu[1] = false;

    for (int i = 1; i <= 1000000; i += 2) {
        if (isSosu[i]) {
            a.pb(base(1));
        }
        else {
            a.pb(base(0));
        }
    }

    for (int i = 2; i <= 1000000; i += 2) {
        if (i >= 6 && isSosu[i / 2]) {
            c.pb(base(1));
        }
        else {
            c.pb(base(0));
        }
    }

    backup_a = a;
    backup_a_2 = a;

    b = a;
    multiply(a, b);

    for (int i = 0; i < a.size(); i++) {
        auto x = a[i];
        int nowTarget = (i + 1) * 2;

        if (nowTarget > 1000000) {
            continue;
        }

        if (nowTarget <= 4) {
            almost_ans.pb(base(0));
            continue;
        }

        almost_ans.pb(base(round(x.real())));
    }

    multiply(almost_ans, backup_a);
    multiply(c, backup_a_2);

    for (auto& i : almost_ans) {
        i.real(round(i.real()));
        i.imag(0);
    }
    for (auto& i : c) {
        i.real(round(i.real()));
        i.imag(0);
    }

    TESTCASE(T) {
        DINPUT(x);

        if (x == 7) {
            PRINT(1);
            continue;
        }

        ull baseval = almost_ans[x / 2 - 1].real();
        ull nowans = 0;

        if (x % 3 == 0 && isSosu[x / 3]) {
            baseval -= 1;
            nowans += 1;
        }

        ull two_same_value_counts = c[x / 2 - 1].real();
        if (x % 3 == 0 && isSosu[x / 3]) {
            two_same_value_counts--;
        }

        baseval -= two_same_value_counts * 3;
        nowans += two_same_value_counts;

        nowans += baseval / 6;

        if (isSosu[x - 4]) {
            nowans += 1;
        }

        PRINT(nowans);
    }

    return 0;
}