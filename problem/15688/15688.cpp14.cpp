#include <iostream>
#include <cmath>
using namespace std;

const int NUM_MAX = 1000000;
int isNumExist[2][NUM_MAX+1] = {0};

int main(){
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;

  for(int i=0;i<N;i++){
    int input;
    cin >> input;
    isNumExist[(input&0x80000000)>>31][abs(input)]++;
  }

  for(int i=-NUM_MAX;i<=NUM_MAX;i++){
    int signFlag = (i<0) ? 1 : 0;
    int absi=abs(i);
    while(isNumExist[signFlag][absi]){
      cout << i << '\n';
      isNumExist[signFlag][absi]--;
    }
  }

  return 0;
}