#include <iostream>
#include <algorithm>
#include <climits>
#define MIN(x,y) ((x)<(y)?(x):(y))
using namespace std;

int pos[200000];

bool Check(int distance, int n, int c){
  int last_pos = pos[0];

  for (int j = 1; j < n; j++){
    if (pos[j] - last_pos >= distance){
      if(--c == 1) return true;
      last_pos = pos[j];
    }
  }

  return false;
}

int main(){
  ios_base::sync_with_stdio(false);

  int n, c, left_ans = INT_MAX, right_ans;
  cin >> n >> c;
  for (int i = 0; i < n; i++) cin >> pos[i];
  sort(pos, pos + n);

  for (int i = 1; i < n; i++) left_ans = MIN(left_ans, pos[i] - pos[i - 1]);
  right_ans = pos[n - 1] - pos[0];

  while (left_ans < right_ans){
    int mid_ans = (left_ans + right_ans + 1) / 2;
    if (Check(mid_ans, n, c)) left_ans = mid_ans;
    else right_ans = mid_ans - 1;
  }

  cout << left_ans;
  return 0;
}