#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
  long long colorMulti[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
  char* colorStr[10] = {"black","brown","red","orange","yellow","green","blue","violet","grey","white"};
  string myColor[3];
  int myColorNum[3] = {0};

  cin >> myColor[0] >> myColor[1] >> myColor[2];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 10; j++) {
      if (strcmp(myColor[i].c_str(), colorStr[j]) == 0) {
        myColorNum[i] = j;
        break;
      }
    }
  }

  long long result = ((myColorNum[0] * 10) + myColorNum[1]) * colorMulti[myColorNum[2]];
  cout << result;
  return 0;
}