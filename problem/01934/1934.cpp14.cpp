#include <iostream>
using namespace std;

#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX(x,y) (((x)>(y))?(x):(y))

int GetLCM(int x, int y){
  for(int i=1;i<=MIN(x,y);i++){
    if((MAX(x,y)*i)%MIN(x,y) == 0)
        return MAX(x,y)*i;
  }
  return 0;
}

int main(){
  int T;
  cin >> T;

  for(int i=0;i<T;i++){
    int A, B;
    cin >> A >> B;
    cout << GetLCM(A,B) << '\n';
  }
  
  return 0;
}