#include <iostream>
using namespace std;

bool num[2][1000001];

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;

    if (input >= 0) num[0][input] = true;
    else num[1][-input] = true;
  }

  for (int i = 1000000; i >= 0; i--) {
    if (num[0][i]) cout << i << '\n';
  }

  for (int i = -1; i >= -1000000; i--) {
    if (num[1][-i]) cout << i << '\n';
  }

  return 0;
}