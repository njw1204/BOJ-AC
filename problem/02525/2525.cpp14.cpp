#include <iostream>
using namespace std;

int main() {
  int hour, min, X;

  cin >> hour >> min >> X;

  min += X;
  hour += min / 60;
  min %= 60;
  hour %= 24;

  printf("%d %d", hour, min);
  return 0;
}