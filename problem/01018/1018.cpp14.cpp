#include <iostream>
#include <string>
#define MIN(x,y) ((x)<(y)?(x):(y))
using namespace std;

string pan[50];

int GetPaintCnt(int start_y, int start_x){
  int temp_ans1 = 0, temp_ans2 = 0;

  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      char temp = (i + j) % 2 ? 'W' : 'B';
      if (pan[start_y + i][start_x + j] == temp) temp_ans1++;
      else temp_ans2++;
    }
  }

  return MIN(temp_ans1, temp_ans2);
}

int main()
{
  int N, M, ans = 0x5A5B5C5D;
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> pan[i];

  for (int i = 0; i + 7 < N; i++){
    for (int j = 0; j + 7 < M; j++)
      ans = MIN(ans, GetPaintCnt(i, j));
  }

  cout << ans;
  return 0;
}