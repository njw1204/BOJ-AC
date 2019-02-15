#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  int P;
  cin >> P;
  for (int i = 0; i < P; i++){
    int N; cin >> N;
    double D, A, B, F; cin >> D >> A >> B >> F;
    printf("%d %.2lf\n", N, D / (A + B)*F);
  }
  return 0;
}