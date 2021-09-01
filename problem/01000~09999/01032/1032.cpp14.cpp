#include <iostream>
#include <string>
using namespace std;

int main() {
  int file_count, file_len;
  cin >> file_count;
  string* file_list = new string[file_count+1];
  for (int i = 0; i < file_count; i++) cin >> file_list[i];
  file_len = file_list[0].size();
  file_list[file_count] = file_list[0];
  for (int i = 0; i < file_len; i++) {
    char cmp_char = file_list[0][i];
    for (int j = 0; j < file_count; j++) {
      if (file_list[j][i] != cmp_char) file_list[file_count][i] = '?';
    }
  }
  cout << file_list[file_count];
  delete[] file_list;
  return 0;
}