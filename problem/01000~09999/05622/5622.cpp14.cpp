#include <iostream>
#include <cstring>
using namespace std;

const int cost[26] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};

int main() {
  int result = 0;
  char input[16];
  cin >> input;

  for (int i = 0; i < strlen(input); i++) {
    result += cost[input[i] - 'A'];
  }

  cout << result;
  return 0;
}