#include <iostream>
using namespace std;

inline int MAX(int x,int y) { return x>y?x:y; }

int val[100000];
int dp[100000];

int main() {
  int N, max_val;
  cin >> N;
  for(int i=0;i<N;i++) cin >> val[i];

  dp[0]=val[0];
  max_val=val[0];
 
  for(int i=1;i<N;i++){
    dp[i]=MAX(dp[i-1]+val[i],val[i]);
    max_val=MAX(max_val,dp[i]);
  }
  
  cout << max_val;
  return 0;
}