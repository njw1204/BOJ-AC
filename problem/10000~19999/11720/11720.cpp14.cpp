#include <iostream>
using namespace std;

int main() {
  int N, result=0;
  char X[101] = {0};
  cin >> N >> X;
  for (int i = 0; i < N; i++) {
    result += X[i] - '0';
  }
  cout << result;
  return 0;
}