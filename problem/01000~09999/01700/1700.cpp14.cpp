#include <iostream>
using namespace std;

int main() {
  int plug[100] = {};
  int arr[100] = {};
  int N, K, nowPlug = 0, count = 0;
  cin >> N >> K;

  for (int i = 0; i < K; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < K; i++) {
    bool jump = false;

    for (int j = 0; j < N; j++) {
      if (arr[i] == plug[j]) {
        jump = true;
        break;
      }
    }

    if (jump) continue;

    if (nowPlug < N) {
      plug[nowPlug] = arr[i];
      nowPlug++;
    } else {
      int max_arr_index = -1, max_plug_index = -1;
      for (int j = 0; j < N; j++) {
        for (int k = i; k < K; k++) {
          if (plug[j] == arr[k]) {
            if (k > max_arr_index) {
              max_arr_index = k;
              max_plug_index = j;
            }
            break;
          } else if (k == K - 1) {
            max_arr_index = K;
            max_plug_index = j;
          }
        }
      }
      plug[max_plug_index] = arr[i];
      count++;
    }
  }

  cout << count;

  return 0;
}