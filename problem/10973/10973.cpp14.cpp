#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000];

int main() {
  int N;
  cin >> N;
  for(int i=0;i<N;i++) cin >> arr[i];
  if(prev_permutation(arr,arr+N)==false){
   cout << -1;
   return 0;
  }
  for(int i=0;i<N;i++) cout << arr[i] << ' ';
  return 0;
}