#include <iostream>
using namespace std;

int dp[10001][2] = {};
int value[10001] = {};

inline int MAX(int x, int y, int z){
  int temp = (x>y)?x:y;
  return (temp>z)?temp:z;
}

int main(){
  int N;
  
  cin >> N;
  for(int i=1;i<=N;i++) cin >> value[i];
  dp[1][1] = value[1];

  for(int i=2;i<=N;i++){
    dp[i][0] = MAX(dp[i-1][0],dp[i-1][1],dp[i-1][2]);
    dp[i][1] = dp[i-1][0] + value[i];
    dp[i][2] = dp[i-1][1] + value[i];
  }

  cout << MAX(dp[N][0],dp[N][1],dp[N][2]);
  return 0;
}