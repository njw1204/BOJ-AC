#include <iostream>
#include <string>
using namespace std;

int main() {
  int A, B, C;
  int count[10] = {0};
  cin >> A >> B >> C;
  string result = to_string(A*B*C);
  for (int i = 0; i < result.size(); i++) count[result[i] - '0']++;
  for (int i = 0; i < 10; i++) cout << count[i] << '\n';
  return 0;
}