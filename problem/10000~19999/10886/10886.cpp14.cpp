#include <iostream>
using namespace std;

int main(){
  int N, input, score=0;
  cin >> N;
  
  for(int i=0;i<N;i++){
    cin >> input;
    (input==1) ? (score++) : (score--);
  }

  if(score>0) cout << "Junhee is cute!";
  else cout << "Junhee is not cute!";
  return 0;
}