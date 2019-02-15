#include <iostream>
using namespace std;

int Remake(int& K) {
  int right = 0, weight = 2, leng = 0;
  while (K > right) {
    right += weight;
    weight *= 2;
    leng += 1;
  }
  K -= (right - weight / 2) + 1;
  return leng - 1;
}

int main() {
  int K;
  cin >> K;
  for (int i = Remake(K); i >= 0; i--)
    ((K >> i) & 1) ? (cout << 7) : (cout << 4);
  return 0;
}