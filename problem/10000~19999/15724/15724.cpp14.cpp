#include <iostream>
using namespace std;

int x;
int dp[1111][1111];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>x;
      dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+x;
    }
  }
  cin>>n;
  for(int i=0;i<n;i++){
    int x,y,a,b;
    cin>>x>>y>>a>>b;
    cout<<dp[a][b]-dp[x-1][b]-dp[a][y-1]+dp[x-1][y-1]<<'\n';
  }
}