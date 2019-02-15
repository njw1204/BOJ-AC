#include <iostream>
#include <string>
using namespace std;

int main(){
  int A, B;

  while(1){
    cin >> A >> B;
    if(A==0) break;
    else cout << A+B << '\n';
  }

  return 0;
}