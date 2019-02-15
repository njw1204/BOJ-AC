#include <iostream>
#include <cmath>
using namespace std;

int main() {
  float T, x1, y1, x2, y2, r1, r2; int count;
  cin >> T;
  for (int i = 0; i<T; i++) {
    count = 0;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if (x1 == x2 && y1 == y2 && r1 == r2) {
      puts("-1");
      continue;
    }
    float distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    float rsum = r1 + r2;

    if (distance>rsum) count = 0;
    else if (distance == rsum) count = 1;
    else if (distance<rsum && (r1 - r2 <distance && r2 - r1 < distance)) count = 2;
    else if (distance<rsum && (r1 - distance == r2 || r2 - distance == r1)) count = 1;
    else count = 0;

    printf("%d\n", count);
  }
  return 0;
}