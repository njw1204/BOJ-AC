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
#define $1 first
#define $2 second
#define pb push_back
#define INF 0x5A5B5C5D
#define INF2 0x77777777
#define INT_MAX 0x7FFFFFFF
#define UINT_MAX (ui)0xFFFFFFFF
#define LL_MAX (ll)0x7FFFFFFFFFFFFFFF
#define ULL_MAX (ull)0xFFFFFFFFFFFFFFFF
#define PI 3.1415926535897932
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define REP(i,n) for(ull i=0;i<(n);i++)
#define ALL(list) (list).begin(),(list).end()
#define PRESENT(list,x) (find(ALL(list),x)!=(list).end())
#define INPUT(cin_a) cin>>(cin_a)
#define INPUT2(cin_a,cin_b) cin>>(cin_a)>>(cin_b)
#define INPUT3(cin_a,cin_b,cin_c) cin>>(cin_a)>>(cin_b)>>(cin_c)
#define DINPUT(int_a) int (int_a);scanf("%d",&(int_a))
#define DINPUT2(int_a,int_b) int (int_a),(int_b);scanf("%d%d",&(int_a),&(int_b))
#define DINPUT3(int_a,int_b,int_c) int (int_a),(int_b),(int_c);scanf("%d%d%d",&(int_a),&(int_b),&(int_c))
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
#else
#define READTXT
#endif
#define TXTPATH "_input.txt"
inline ull GCD(ull a, ull b) { while (b != 0) { ull t = a % b; a = b; b = t; } return a; }
inline ull LCM(ull a, ull b) { return a * b / GCD(a, b); }

int main() {
  READTXT;
  queue<int> myQueue;
  DINPUT(T);
  cin.ignore(1, '\n');

  REP(i,T){
    string input;
    getline(cin, input);
    string temp = input.substr(0, 2);

    if (temp == "pu") {
      myQueue.push(stoi(input.substr(input.find(' ') + 1)));
    } else if (temp == "po") {
      if (myQueue.empty()) PRINT(-1);
      else {
        PRINT(myQueue.front());
        myQueue.pop();
      }
    } else if (temp == "si") {
      PRINT(myQueue.size());
    } else if (temp == "em") {
      PRINT(int(myQueue.empty()));
    } else if (temp == "fr") {
      if (myQueue.empty()) PRINT(-1);
      else PRINT(myQueue.front());
    } else {
      if (myQueue.empty()) PRINT(-1);
      else PRINT(myQueue.back());
    }
  }

  return 0;
}