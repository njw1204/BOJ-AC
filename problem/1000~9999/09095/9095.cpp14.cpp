#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  int* N = new int[T];
  for (int i = 0; i < T; i++) {
    cin >> N[i];
  }

  int CombiCount[10] = {1,2,4};
  for (int i = 3; i < 10; i++) {
    CombiCount[i] = CombiCount[i - 3] + CombiCount[i - 2] + CombiCount[i - 1] ;
  }

  for (int num_case = 0; num_case < T; num_case++) {
    cout << CombiCount[N[num_case] - 1] << '\n';
  }

  delete[] N;
  return 0;
}