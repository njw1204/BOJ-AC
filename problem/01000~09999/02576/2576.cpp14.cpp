#include <iostream>
using namespace std;

int main(){
  int num[7] = {0};
  int num_count = 0;

  for(int i=0;i<7;i++){
    int input;
    cin >> input;
    if(input%2==1){
      num[num_count]=input;
      num_count++;
    }
  }
  
  if(num_count==0){
    cout << -1;
    return 0;
  }

  int min_num = 100, result = 0;
  for(int i=0;i<num_count;i++){
    if(num[i]<min_num) min_num = num[i];
    result += num[i];
  }
  
  cout << result << '\n' << min_num;
  return 0;
}