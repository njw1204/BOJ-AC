#include <iostream>
#include <vector>
#define MIN(x,y) ((x)<(y)?(x):(y))
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  vector<int> lion;
  int N, K;
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    if (input == 1) lion.push_back(i);
  }

  if (lion.size() < K) {
    cout << -1;
    return 0;
  }

  int ans = 0x7FFFFFFF, lion_size = lion.size();
  for (int i = 0; i + K - 1 < lion_size; i++)
    ans = MIN(ans, lion[i + K - 1] - lion[i] + 1);

  cout << ans;
  return 0;
}