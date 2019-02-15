#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  bool homework[30] = {0};

  for (int i = 0; i < 28; i++) {
    int input;
    cin >> input;
    homework[input-1] = true;
  }

  for (int i = 0; i < 30; i++) {
    if (homework[i] == false) cout << i+1 << '\n';
  }

  return 0;
}