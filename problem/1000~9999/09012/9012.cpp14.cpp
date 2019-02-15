#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    string PS;
    cin >> PS;
    int PS_size = PS.size(), state = 0;
    
    for (int j = 0; (j < PS_size) && (state >= 0); j++) {
      if (PS[j] == '(') state++;
      else state--;
    }

    if (state == 0) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}