#include <iostream>
using namespace std;

int main(){
  int count;
  cin >> count;
  int* num_array = new int[count];
  for(int i=0;i<count;i++) cin >> num_array[i];
  for(int i=1;i<count;i++){
    int key=num_array[i], j;
    for(j=i-1;j>=0;j--){
      if(num_array[j]>key) num_array[j+1] = num_array[j];
      else break;
    }
    num_array[j+1] = key;
  }
  for(int i=0;i<count;i++) {
    cout << num_array[i];
    if(i<count-1) cout << '\n';
  }
  delete[] num_array;
  return 0;
}