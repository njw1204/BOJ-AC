#include <iostream>
#include <cmath>
using namespace std;
 
long long sum(long long n) {
  long long r = sqrt(n), ans = 0, m = 0;
  for (int i = 1; i <= r; i++) {
    ans += n / i;
    if (n % i == 0) {
      if (n / i != i) m++;
      m++;
    }
  }
  return ans * 2 - r * r + n - m;
}

int main() {
  long long n, ans;
  cin >> n;
  ans = sum(n);
  cout << ans << endl;
  return 0;
}