#include <iostream>
#include <cstring>
using namespace std;

int main() {
  int arr[20] = {};
  char numStr[20];
  cin >> numStr;

  for (int i = 0; i < strlen(numStr); i++)
    arr[i] = numStr[i] - '0';

  for (int i = 0; i < strlen(numStr) - 1; i++) {
    int max_val = arr[i], max_pos = i;
    for (int j = i; j < strlen(numStr); j++) {
      if (arr[j] > max_val) {
        max_val = arr[j];
        max_pos = j;
      }
    }
    int t = arr[i];
    arr[i] = arr[max_pos];
    arr[max_pos] = t;
  }

  for (int i = 0; i < strlen(numStr); i++) cout << arr[i];
  return 0;
}