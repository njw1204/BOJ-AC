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
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <climits>
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

int R, C;
char field[25][25];
map<pair<pair<int, int>, int>, bool> visitMap;

int Hash(int origin, char next) {
  int pos = next - 'A';
  origin |= 1 << pos;
  return origin;
}

bool Visit(int hashVal, char next) {
  int pos = next - 'A';
  if (hashVal & (1 << pos)) return true;
  else return false;
}

int BFS(int si, int sj) {
  queue<pair<pair<int, int>, pair<int, int>>> Q;
  Q.push({ {si,sj},{Hash(0,field[si][sj]),1} });
  visitMap[{ {si, sj}, Q.front().$2.$1}] = true;
  int answer = 1;

  while (!Q.empty()) {
    auto i = Q.front();
    answer = MAX(answer, Q.front().$2.$2);
    Q.pop();
    pair<int, int> dx[4] = { {0,1},{0,-1},{1,0},{-1,0} };
    for (int j = 0; j < 4; j++) {
      if (field[i.$1.$1 + dx[j].$1][i.$1.$2 + dx[j].$2] && !Visit(i.$2.$1, field[i.$1.$1 + dx[j].$1][i.$1.$2 + dx[j].$2])
        && !visitMap[{ {i.$1.$1 + dx[j].$1, i.$1.$2 + dx[j].$2}, Hash(i.$2.$1, field[i.$1.$1 + dx[j].$1][i.$1.$2 + dx[j].$2])}]) {
        int hash = Hash(i.$2.$1, field[i.$1.$1 + dx[j].$1][i.$1.$2 + dx[j].$2]);
        Q.push({ {i.$1.$1 + dx[j].$1, i.$1.$2 + dx[j].$2}, {hash, i.$2.$2 + 1} });
        visitMap[{ {i.$1.$1 + dx[j].$1, i.$1.$2 + dx[j].$2}, Hash(i.$2.$1, field[i.$1.$1 + dx[j].$1][i.$1.$2 + dx[j].$2])}] = true;
      }
    }
  }

  return answer;
}

int main() {
  READTXT;
  DINPUT2(R, C);
  for (int i = 1; i <= R; i++) {
    getchar();
    for (int j = 1; j <= C; j++) {
      scanf("%c", &field[i][j]);
    }
  }

  cout << BFS(1, 1);
  return 0;
}