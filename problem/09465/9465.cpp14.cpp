#include <iostream>
#define MAX(x,y) ((x)>(y)?(x):(y))
using namespace std;

char arr[2][100000];
int dp[2][100000];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int T;
  cin >> T;

  for (int i = 0; i < T; i++){
    int N;
    cin >> N;

    for (int j = 0; j < 2; j++){
      for (int k = 0; k < N; k++){
        int input;
        cin >> input;
        arr[j][k] = input;
      }
    }

    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];

    for (int j = 1; j < N; j++){
      dp[0][j] = MAX(dp[1][j - 1], dp[1][j - 2]) + arr[0][j];
      dp[1][j] = MAX(dp[0][j - 1], dp[0][j - 2]) + arr[1][j];
    }

    cout << MAX(dp[0][N - 1], dp[1][N - 1]) << '\n';
  }

  return 0;
}