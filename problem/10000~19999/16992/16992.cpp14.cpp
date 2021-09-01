#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
#include <array>
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
#include <regex>
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
#define $1 first
#define $2 second
#define pb push_back
#define INF 0x5A5B5C5D
#define INF2 0x77777777
#define PI 3.1415926535897932
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX3(x,y,z) (MAX(MAX(x,y),z))
#define MIN3(x,y,z) (MIN(MIN(x,y),z))
#define MAX4(a,b,c,d) (MAX(MAX3(a,b,c),d))
#define MIN4(a,b,c,d) (MIN(MIN3(a,b,c),d))
#define MEDIAN(x,y,z) (MIN(MAX(x,y),z)==z?MAX(MIN(x,y),z):MAX(x,y))
#define REP(i,n) for(int (i)=0;(i)<int(n);(i)++)
#define ALL(list) (list).begin(),(list).end()
#define PRESENT(list,x) (find(ALL(list),x)!=(list).end())
#define INPUT(cin_a) cin>>(cin_a)
#define INPUT2(cin_a,cin_b) cin>>(cin_a)>>(cin_b)
#define INPUT3(cin_a,cin_b,cin_c) cin>>(cin_a)>>(cin_b)>>(cin_c)
#define DINPUT(int_a) int (int_a);INPUT(int_a)
#define DINPUT2(int_a,int_b) int (int_a),(int_b);INPUT2(int_a,int_b)
#define DINPUT3(int_a,int_b,int_c) int (int_a),(int_b),(int_c);INPUT3(int_a,int_b,int_c)
#define DSCANF(int_a) int (int_a);scanf("%d",&(int_a))
#define DSCANF2(int_a,int_b) int (int_a),(int_b);scanf("%d%d",&(int_a),&(int_b))
#define DSCANF3(int_a,int_b,int_c) int (int_a),(int_b),(int_c);scanf("%d%d%d",&(int_a),&(int_b),&(int_c))
#define TESTCASE(T) DINPUT(i_i__ai);for(int (T)=1;(T)<=i_i__ai;(T)++)
#define INIT(arr) memset((arr),0,sizeof(arr))
#define FILL(a,x) for(auto& acm_icpc:(a))acm_icpc=(x);
#define BETWEEN(x,low,high) ((x)>=(low)&&(x)<=(high))
#define ctoi(ch) ((ch)-'0')
#define countof(arr) (sizeof(arr)/sizeof((arr)[0]))
#define endl '\n'
#define PRINT(cout_x) cout<<(cout_x)<<endl
#define DEBUG(cout_x) cout<<">> "<<#cout_x<<" = "<<(cout_x)<<endl
#ifdef MY_ALGO
#define READTXT freopen(TXTPATH,"r",stdin)
#define UNSYNC ios_base::sync_with_stdio(false)
#else
#define READTXT
#define UNSYNC ios_base::sync_with_stdio(false);cin.tie(nullptr)
#endif
#define TXTPATH "_input.txt"
inline ull GCD(ull a, ull b) { while (b != 0) { ull t = a % b; a = b; b = t; } return a; }
inline ull LCM(ull a, ull b) { return a * b / GCD(a, b); }

int N, M, ans;
bool flag[100];
int clause[1000][3];

bool CheckClause(int idx) {
    for (int i = 0; i < 3; i++) {
        if (flag[abs(clause[idx][i]) - 1] == (clause[idx][i] > 0))
            return true;
    }
    return false;
}

bool CheckClause2(int idx, int i) {
    return (flag[abs(clause[idx][i]) - 1] == (clause[idx][i] > 0));
}

int main() {
    UNSYNC; READTXT;
    random_device rn;
    srand(rn());
    cin >> N >> M;

    REP(i, M) {
        cin >> clause[i][0] >> clause[i][1] >> clause[i][2];
    }

    for (int i = 0; i < 11000 && !ans; i++) {
        flag[rand() % N] = true;
        for (int round = 0; round < N * 4; round++) {
            int j, inj = rand() % M;
            for (j = inj; j < inj + M; j++) {
                if (!CheckClause(j % M)) break;
            }
            if (j == inj + M) {
                ans = 1;
                break;
            }
            j %= M;

            int cnt = 0;
            int arr[3] = {};
            for (int k = 0; k < 3; k++) {
                if (!CheckClause2(j, k)) {
                    arr[cnt++] = abs(clause[j][k]) - 1;
                }
            }

            flag[arr[rand() % cnt]] = !flag[arr[rand() % cnt]];
        }
    }

    cout << ans << endl;
    if (ans) {
        for (int i = 0; i < N; i++)
            cout << flag[i] << ' ';
    }
}