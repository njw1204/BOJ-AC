#include <iostream>
#include <cstring>
using namespace std;
#define MAX(x,y) ((x)>(y)?(x):(y))
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define INPUT(cin_a) cin>>(cin_a)
#define INPUT2(cin_a,cin_b) cin>>(cin_a)>>(cin_b)
#define DINPUT(int_a) int (int_a);INPUT(int_a)
#define DINPUT2(int_a,int_b) int (int_a),(int_b);INPUT2(int_a,int_b)
#define TESTCASE(T) DINPUT(i_i__ai);for(int (T)=1;(T)<=i_i__ai;(T)++)
#define INIT(arr) memset((arr),0,sizeof(arr))
#define FILL(a,x) for(auto& acm_icpc:(a))acm_icpc=(x);
#define PRINT(cout_x) cout<<(cout_x)<<endl
#define UNSYNC ios_base::sync_with_stdio(false);cin.tie(nullptr)

int N, K;
int startTime[1000];
int buildTime[1000];
bool link[1000][1000];

int DFS(int start) {
  if (startTime[start] == -1) {
    startTime[start] = 0;
    REP(i, N) {
      if (link[start][i]) startTime[start] = MAX(startTime[start], DFS(i));
    }
  }
  return startTime[start] + buildTime[start];
}

int main(){
  UNSYNC;
  TESTCASE(T) {
    INIT(link); FILL(startTime, -1);
    INPUT2(N, K);
    REP(i, N) INPUT(buildTime[i]);
    REP(i, K) {
      DINPUT2(a, b);
      link[b - 1][a - 1] = true;
    }
    DINPUT(W);
    PRINT(DFS(W - 1));
  }
  return 0;
}