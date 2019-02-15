#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int alphaCount[26] = {0};
  string input;
  cin >> input;

  for (int i = 0; i < input.size(); i++) {
    alphaCount[input[i] - 'a']++;
  }

  for_each(alphaCount, alphaCount + 26, [](int a) {cout << a << ' '; });

  return 0;
}