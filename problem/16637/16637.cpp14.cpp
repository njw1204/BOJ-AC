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
#define REP(i,n) for(ull (i)=0;(i)<ull(n);(i)++)
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

struct expr {
    char type;
    int val;
    char op;
};

int N;
string E;
vector<expr> fullEx;
int ans = INT_MIN;

int oper(int x, int y, char op) {
    switch (op) {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    }
    return 0;
}

int calc(vector<expr> ex, const vector<int>& parenthesis) {
    vector<int> paResult;

    for (auto i : parenthesis) {
        array<expr, 3> tmp;
        for (int j = 0; j < 3; j++)
            tmp[j] = ex[i + j];
        paResult.pb(oper(tmp[0].val, tmp[2].val, tmp[1].op));
    }

    for (int i = 0; i < parenthesis.size(); i++) {
        ex[parenthesis[i]] = { 1, paResult[i], 0 };
        ex[parenthesis[i] + 1] = { 0, 0, 0 };
        ex[parenthesis[i] + 2] = { 0, 0, 0 };
    }

    int x, y, cnt = 0, lastVal;
    char op;

    for (auto& i : ex) {
        if (i.type == 0) continue;
        
        if (cnt == 0) {
            x = i.val;
            lastVal = x;
            cnt = 1;
        }
        else if (cnt == 1) {
            op = i.op;
            cnt = 2;
        }
        else {
            y = i.val;
            i.val = oper(x, y, op);
            x = i.val;
            lastVal = x;
            cnt = 1;
        }
    }

    return lastVal;
}

int solve(vector<int>& parenthesis, int lastPa) {
    if (lastPa >= N - 5) {
        return calc(fullEx, parenthesis);
    }

    int a = solve(parenthesis, lastPa + 2);
    parenthesis.pb(lastPa + 4);
    int b = solve(parenthesis, lastPa + 4);
    parenthesis.pop_back();
    return max(a, b);
}

int main() {
    UNSYNC; READTXT;
    INPUT2(N, E);

    for (auto i : E) {
        if (isdigit(i)) {
            fullEx.pb({ 1, i - '0', 0 });
        }
        else {
            fullEx.pb({ 2, 0, i });
        }
    }

    vector<int> parenthesis;
    cout << solve(parenthesis, -4) << endl;
}