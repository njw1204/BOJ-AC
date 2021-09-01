#include <iostream>
using namespace std;

int main(){
  int total_kg, max_5, i;
  cin >> total_kg;
  max_5 = total_kg / 5;
  for(i=max_5;i>=0;i--){
    if((total_kg-i*5)%3==0) {
      printf("%d",i+(total_kg-i*5)/3);
      return 0;
    }
  }
  printf("-1");
  return 0;
}