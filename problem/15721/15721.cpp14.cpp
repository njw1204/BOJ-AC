#include <iostream>
using namespace std;

int A, T, ty;
int num;
int cnt[2];

int main() {
  cin >> A >> T >> ty;

  for (int level = 2; ; level++){
    for (int i = 0; i < 2; i++){
      cnt[0]++;
      if (cnt[ty] == T) goto fin;
      num++;
      cnt[1]++;
      if (cnt[ty] == T) goto fin;
      num++;
    }
    for (int i = 0; i < level; i++){
      cnt[0]++;
      if (cnt[ty] == T) goto fin;
      num++;
    }
    for (int i = 0; i < level; i++){
      cnt[1]++;
      if (cnt[ty] == T) goto fin;
      num++;
    }
  }

fin:
  cout << num % A;
}