#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,from,to) for(auto i=(from);i<=(to);i++)
#define FORS(i,from,to,step) for(auto i=(from);i<=(to);i+=(step))
#define FOREACH(i,a) for(const auto& i:a)
#define ALL(list) (list).begin(),(list).end()
#define PRESENT(list,x) (find(ALL(list),x)!=(list).end())
#define INPUT(cin_a) cin>>(cin_a)
#define INPUT2(cin_a,cin_b) cin>>(cin_a)>>(cin_b)
#define INPUT3(cin_a,cin_b,cin_c) cin>>(cin_a)>>(cin_b)>>(cin_c)
#define DINPUT(ll_a) ll (ll_a);INPUT(ll_a)
#define DINPUT2(ll_a,ll_b) ll (ll_a),(ll_b);INPUT2(ll_a,ll_b)
#define DINPUT3(ll_a,ll_b,ll_c) ll (ll_a),(ll_b),(ll_c);INPUT3(ll_a,ll_b,ll_c)
#define INIT(arr) memset((arr),0,sizeof(arr))
#define FILL(a,x) for(auto& i:(a))i=(x);
#define BETWEEN(x,low,high) ((x)>=(low)&&(x)<=(high))
#define ctoi(ch) ((ch)-'0')
#define countof(arr) sizeof(arr)/sizeof((arr)[0])
#define endl '\n'
#define RET return 0
#define PRINT(x) cout<<(x)<<endl
#define DEBUG(x) cout<<">> "<<#x<<" = "<<x<<endl
inline ull GCD(ull a, ull b) { while (b != 0) { ull t = a % b; a = b; b = t; } return a; }
inline ull LCM(ull a, ull b) { return a * b / GCD(a, b); }

int main() {
  DINPUT(T);
  REP(i, T) {
    int value = 0;
    bool digit[10] = {};
    DINPUT(X);
    while (X > 0) {
      digit[X % 10] = true;
      X /= 10;
    }
    FOREACH(i, digit) if (i) value++;
    PRINT(value);
  }
  RET;
}