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
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <climits>
#include <regex>
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
#ifndef ONLINE_JUDGE
#define READTXT freopen(TXTPATH,"r",stdin)
#define UNSYNC ios_base::sync_with_stdio(false)
#else
#define READTXT
#define UNSYNC ios_base::sync_with_stdio(false);cin.tie(nullptr)
#endif
#define TXTPATH "_input.txt"
inline ull GCD(ull a, ull b) { while (b != 0) { ull t = a % b; a = b; b = t; } return a; }
inline ull LCM(ull a, ull b) { return a * b / GCD(a, b); }

int n, m, blank;
char ma[55][55];
char flow[55][55][55][55], flow2[55][55], flow3[55][55];
char mflow[55][55][55][55], mflow2[55][55], mflow3[55][55];

int main() {
    UNSYNC; READTXT;
    INPUT2(n, m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ma[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ma[i][j] == '.') {
                blank++;
                if ((i + j) % 2 == 1) {
                    // out node
                    mflow3[i][j] = 1;
                }
                else {
                    // in node
                    mflow2[i][j] = 1;
                    if (ma[i][j + 1] == '.') {
                        mflow[i][j][i][j + 1] = 1;
                    }
                    if (ma[i][j - 1] == '.') {
                        mflow[i][j][i][j - 1] = 1;
                    }
                    if (ma[i + 1][j] == '.') {
                        mflow[i][j][i + 1][j] = 1;
                    }
                    if (ma[i - 1][j] == '.') {
                        mflow[i][j][i - 1][j] = 1;
                    }
                }
            }
        }
    }

    while (true) {
        queue<pair<int, int>> Q;
        bool visit[55][55] = {};
        pair<int, int> parent[55][55];
        Q.push({ 0,0 });
        visit[0][0] = true;
        int mif = INT_MAX;

        while (!Q.empty()) {
            auto i = Q.front();
            if (i.$1 == 54 && i.$2 == 54) {
                // final node
                break;
            }
            Q.pop();

            if (i.$1 == 0 && i.$2 == 0) {
                // init node
                for (int j = 1; j <= n; j++) {
                    for (int k = 1; k <= m; k++) {
                        if ((j + k) % 2 == 0 && ma[j][k] == '.' && !visit[j][k] && flow2[j][k] < mflow2[j][k]) {
                            mif = min(mif, mflow2[j][k] - flow2[j][k]);
                            parent[j][k] = i;
                            visit[j][k] = true;
                            Q.push({ j, k });
                        }
                    }
                }
            }
            else if ((i.$1 + i.$2) % 2 == 0) {
                // in node
                if (ma[i.$1][i.$2 + 1] == '.' && !visit[i.$1][i.$2 + 1] && flow[i.$1][i.$2][i.$1][i.$2 + 1] < mflow[i.$1][i.$2][i.$1][i.$2 + 1]) {
                    mif = min(mif, mflow[i.$1][i.$2][i.$1][i.$2 + 1] - flow[i.$1][i.$2][i.$1][i.$2 + 1]);
                    parent[i.$1][i.$2 + 1] = i;
                    visit[i.$1][i.$2 + 1] = true;
                    Q.push({ i.$1, i.$2 + 1 });
                }
                if (ma[i.$1][i.$2 - 1] == '.' && !visit[i.$1][i.$2 - 1] && flow[i.$1][i.$2][i.$1][i.$2 - 1] < mflow[i.$1][i.$2][i.$1][i.$2 - 1]) {
                    mif = min(mif, mflow[i.$1][i.$2][i.$1][i.$2 - 1] - flow[i.$1][i.$2][i.$1][i.$2 - 1]);
                    parent[i.$1][i.$2 - 1] = i;
                    visit[i.$1][i.$2 - 1] = true;
                    Q.push({ i.$1, i.$2 - 1 });
                }
                if (ma[i.$1 + 1][i.$2] == '.' && !visit[i.$1 + 1][i.$2] && flow[i.$1][i.$2][i.$1 + 1][i.$2] < mflow[i.$1][i.$2][i.$1 + 1][i.$2]) {
                    mif = min(mif, mflow[i.$1][i.$2][i.$1 + 1][i.$2] - flow[i.$1][i.$2][i.$1 + 1][i.$2]);
                    parent[i.$1 + 1][i.$2] = i;
                    visit[i.$1 + 1][i.$2] = true;
                    Q.push({ i.$1 + 1, i.$2 });
                }
                if (ma[i.$1 - 1][i.$2] == '.' && !visit[i.$1 - 1][i.$2] && flow[i.$1][i.$2][i.$1 - 1][i.$2] < mflow[i.$1][i.$2][i.$1 - 1][i.$2]) {
                    mif = min(mif, mflow[i.$1][i.$2][i.$1 - 1][i.$2] - flow[i.$1][i.$2][i.$1 - 1][i.$2]);
                    parent[i.$1 - 1][i.$2] = i;
                    visit[i.$1 - 1][i.$2] = true;
                    Q.push({ i.$1 - 1, i.$2 });
                }
            }
            else {
                // out node
                if (!visit[54][54] && flow3[i.$1][i.$2] < mflow3[i.$1][i.$2]) {
                    mif = min(mif, mflow3[i.$1][i.$2] - flow3[i.$1][i.$2]);
                    parent[54][54] = i;
                    visit[54][54] = true;
                    Q.push({ 54, 54 });
                }


                if (ma[i.$1][i.$2 + 1] == '.' && !visit[i.$1][i.$2 + 1] && flow[i.$1][i.$2][i.$1][i.$2 + 1] < mflow[i.$1][i.$2][i.$1][i.$2 + 1]) {
                    mif = min(mif, mflow[i.$1][i.$2][i.$1][i.$2 + 1] - flow[i.$1][i.$2][i.$1][i.$2 + 1]);
                    parent[i.$1][i.$2 + 1] = i;
                    visit[i.$1][i.$2 + 1] = true;
                    Q.push({ i.$1, i.$2 + 1 });
                }
                if (ma[i.$1][i.$2 - 1] == '.' && !visit[i.$1][i.$2 - 1] && flow[i.$1][i.$2][i.$1][i.$2 - 1] < mflow[i.$1][i.$2][i.$1][i.$2 - 1]) {
                    mif = min(mif, mflow[i.$1][i.$2][i.$1][i.$2 - 1] - flow[i.$1][i.$2][i.$1][i.$2 - 1]);
                    parent[i.$1][i.$2 - 1] = i;
                    visit[i.$1][i.$2 - 1] = true;
                    Q.push({ i.$1, i.$2 - 1 });
                }
                if (ma[i.$1 + 1][i.$2] == '.' && !visit[i.$1 + 1][i.$2] && flow[i.$1][i.$2][i.$1 + 1][i.$2] < mflow[i.$1][i.$2][i.$1 + 1][i.$2]) {
                    mif = min(mif, mflow[i.$1][i.$2][i.$1 + 1][i.$2] - flow[i.$1][i.$2][i.$1 + 1][i.$2]);
                    parent[i.$1 + 1][i.$2] = i;
                    visit[i.$1 + 1][i.$2] = true;
                    Q.push({ i.$1 + 1, i.$2 });
                }
                if (ma[i.$1 - 1][i.$2] == '.' && !visit[i.$1 - 1][i.$2] && flow[i.$1][i.$2][i.$1 - 1][i.$2] < mflow[i.$1][i.$2][i.$1 - 1][i.$2]) {
                    mif = min(mif, mflow[i.$1][i.$2][i.$1 - 1][i.$2] - flow[i.$1][i.$2][i.$1 - 1][i.$2]);
                    parent[i.$1 - 1][i.$2] = i;
                    visit[i.$1 - 1][i.$2] = true;
                    Q.push({ i.$1 - 1, i.$2 });
                }
            }
        }

        if (!visit[54][54]) break;

        int si = 54, sj = 54;
        while (si != 0 || sj != 0) {
            auto pre = parent[si][sj];
            if (si == 54 && sj == 54) {
                flow3[pre.$1][pre.$2] += mif;
            }
            else if (pre.$1 == 0 && pre.$2 == 0) {
                flow2[si][sj] += mif;
            }
            else {
                flow[pre.$1][pre.$2][si][sj] += mif;
                flow[si][sj][pre.$1][pre.$2] -= mif;
            }
            si = pre.$1;
            sj = pre.$2;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans += flow3[i][j];

    cout << blank - (ans * 2) + ans;
}