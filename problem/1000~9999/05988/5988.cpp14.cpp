#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    string input;
    cin >> input;
    if ((input.back()-'0') % 2) cout << "odd\n";
    else cout << "even\n";
  }

  return 0;
}