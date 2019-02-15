#include <iostream>
#include <string>
using namespace std;

string x;
int answer[1003];

void setting() {
  for (auto& i : answer) i = 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> x;
  setting();
  cout << answer[x.size()];
}