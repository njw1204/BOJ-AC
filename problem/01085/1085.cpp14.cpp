#include <iostream>
using namespace std;

inline int MIN(int x, int y) { return (x < y) ? x : y; }

int main() {
  int x, y, w, h;
  cin >> x >> y >> w >> h;
  cout << MIN(MIN(MIN(h - y, y), x), w - x);
  return 0;
}