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
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <bitset>
#include <limits>
#include <numeric>
#include <iomanip>
#include <regex>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
typedef unsigned int ui;
typedef long long int ll;
typedef unsigned long long int ull;
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define INF 0x5A5B5C5D
#define INF2 0x77777777
#define INT_MAX 0x7FFFFFFF
#define UINT_MAX (ui)0xFFFFFFFF
#define LL_MAX (ll)0x7FFFFFFFFFFFFFFF
#define ULL_MAX (ull)0xFFFFFFFFFFFFFFFF
#define PI 3.141592653589793
#define REP(i,n) for(ull i=0;i<(n);i++)
#define FOR(i,from,to) for(auto i=(from);((to)>=(from))?(i<=(to)):(i>=(to));i+=((to)>=(from))?1:-1)
#define FORS(i,from,to,step) for(auto i=(step)*0+(from);((to)>=(from))?(i<=(to)):(i>=(to));i+=(step))
#define FOREACH(i,a) for(const auto& i:a)
#define ALL(list) (list).begin(),(list).end()
#define PRESENT(list,x) (find(ALL(list),x)!=(list).end())
#define INPUT(cin_a) cin>>(cin_a)
#define INPUT2(cin_a,cin_b) cin>>(cin_a)>>(cin_b)
#define INPUT3(cin_a,cin_b,cin_c) cin>>(cin_a)>>(cin_b)>>(cin_c)
#define DINPUT(ll_a) ll (ll_a);scanf("%lld",&(ll_a))
#define DINPUT2(ll_a,ll_b) ll (ll_a),(ll_b);scanf("%lld%lld",&(ll_a),&(ll_b))
#define DINPUT3(ll_a,ll_b,ll_c) ll (ll_a),(ll_b),(ll_c);scanf("%lld%lld%lld",&(ll_a),&(ll_b),&(ll_c))
#define TESTCASE(T) DINPUT(i_i__i);FOR(T,1,i_i__i)
#define INIT(arr) memset((arr),0,sizeof(arr))
#define FILL(a,x) for(auto& i:(a))i=(x);
#define BETWEEN(x,low,high) ((x)>=(low)&&(x)<=(high))
#define ctoi(ch) ((ch)-'0')
#define countof(arr) (sizeof(arr)/sizeof((arr)[0]))
#define endl '\n'
#define RET return 0
#define PRINT(cout_x) cout<<(cout_x)<<endl
#define DEBUG(cout_x) cout<<">> "<<#cout_x<<" = "<<(cout_x)<<endl
inline ull GCD(ull a, ull b) { while (b != 0) { ull t = a % b; a = b; b = t; } return a; }
inline ull LCM(ull a, ull b) { return a * b / GCD(a, b); }

int main() {
  TESTCASE(N) {
    DINPUT3(R, E, C);
    
    if (R > E - C)
      PRINT("do not advertise");
    else if (R < E - C)
      PRINT("advertise");
    else
      PRINT("does not matter");
  }
  RET;
}