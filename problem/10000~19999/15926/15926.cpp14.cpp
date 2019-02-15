#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

bool galho[1000005];

bool isPair(char a, char b) {
  if (a == '(' && b == ')') return true;
  if (a == '[' && b == ']') return true;
  if (a == '{' && b == '}') return true;
  return false;
}

int main() {
  int TESTCASE = 1, trash;
  cin >> trash;
  for (int T = 1; T <= TESTCASE; T++){
    int ans = 0;
    vector<pair<char, int>> st;
    string x;
    cin >> x;
    memset(galho, 0, sizeof(galho));

    for (int i = 0; i < x.size(); i++) {
      st.push_back(make_pair(x[i], i));
      if (st.size() >= 2 && isPair(st[st.size() - 2].first, st[st.size() - 1].first)) {
        galho[st[st.size() - 1].second] = true;
        galho[st[st.size() - 2].second] = true;
        st.pop_back(); st.pop_back();
      }
    }

    int temp = 0;
    for (int i = 0; i < x.size(); i++) {
      if (galho[i]) temp++;
      else temp = 0;
      if (temp > ans) ans = temp;
    }

    cout << ans << endl;
  }
  return 0;
}