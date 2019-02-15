#include <iostream>
using namespace std;

int main() {
 ios_base::sync_with_stdio(false);
 int T;
 cin >> T;
 for(int i=0;i<T;i++){
  int num,nMin=100,nSum=0;
  for(int j=0;j<7;j++){
   cin >> num;
   if(num%2) num=0;
   if(num>0 && num<nMin) nMin=num;
   nSum+=num;
  }
  cout << nSum << ' ' << nMin << '\n';
 } 
 return 0;
}