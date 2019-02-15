#include <iostream>
#include <string>
using namespace std;

int main() {
  int N, count = 0;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    if (input != i + 1) count++;
  }

  cout << count;
  return 0;
}