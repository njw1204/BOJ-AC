#include <iostream>
#include <string>
using namespace std;

struct SCHOOL {
  char name[21] = {0};
  int value;
};

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N, max_index = 0;
    cin >> N;
    SCHOOL* input = new SCHOOL[N];

    for (int i = 0; i < N; i++) {
      cin >> input[i].name >> input[i].value;
    }

    for (int i = 1; i < N; i++) {
      if (input[i].value > input[max_index].value) max_index = i;
    }

    cout << input[max_index].name << '\n';
    delete[] input;
  }

  return 0;
}