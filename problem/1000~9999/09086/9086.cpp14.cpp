#include <iostream>
#include <string>
using namespace std;
#define DINPUT(i) int i;scanf("%d",&i)
#define TESTCASE(T) DINPUT(i);for(int T=1;T<=i;T++)

int main() {
  TESTCASE(T) {
    string X;
    cin >> X;
    printf("%c%c\n", X[0], X.back());
  }
  return 0;
}