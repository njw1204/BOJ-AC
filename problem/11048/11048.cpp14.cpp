#include <iostream>
using namespace std;

int candy[1001][1001] = {};
int dp[1001][1001] = {};

inline int MAX(int x, int y){ return (x>y)?x:y; }

int GetMaxCandy(int x, int y){
  int first, second;

  if(x==0 || y==0) return 0;

  if(dp[x-1][y] == -1) first = GetMaxCandy(x-1,y);
  else first = dp[x-1][y];
  if(dp[x][y-1] == -1) second = GetMaxCandy(x,y-1);
  else second = dp[x][y-1];

  dp[x][y] = MAX(first,second) + candy[x][y];
  return dp[x][y];
}

int main(){
  int x, y;
  cin >> x >> y;
  for(int i=1;i<=x;i++){
    for(int j=1;j<=y;j++){
      cin >> candy[i][j];
      dp[i][j] = -1;
    }
  }
  cout << GetMaxCandy(x,y);
  return 0;
}