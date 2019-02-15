#include <iostream>
using namespace std;

int main(){
  int A, B;

  while(1){
    cin >> A >> B;
    if(A==0) break;

    if(A>B){
      if(A%B==0) cout << "multiple\n";
      else cout << "neither\n";
    }else{
      if(B%A==0) cout <<"factor\n";
      else cout << "neither\n";
    }
  }

  return 0;
}