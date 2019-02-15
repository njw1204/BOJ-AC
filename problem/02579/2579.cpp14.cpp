#include <iostream>
using namespace std;

int dp[301][3];
int cost[301];

inline int MAX(int x,int y) { return (x>y)?x:y; }

int main() {
	int N;
    cin >> N;
    for(int i=1;i<=N;i++) cin >> cost[i];
    dp[1][1]=cost[1];
    for(int i=2;i<=N;i++){
      dp[i][0]=MAX(dp[i-1][1],dp[i-1][2]);
      dp[i][1]=dp[i-1][0]+cost[i];
      dp[i][2]=dp[i-1][1]+cost[i];
    }
    cout << MAX(dp[N][1],dp[N][2]);
	return 0;
}