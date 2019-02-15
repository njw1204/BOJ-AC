#include <iostream>
#include <algorithm>
using namespace std;

struct ROBOT{
  int no;
  double cost;
};

ROBOT robo[100000];

int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
      int input[3];
      cin >> input[0] >> input[1] >> input[2];
      robo[i].no=i+1;
      robo[i].cost=(input[0]*input[0]+input[1]*input[1])
                   /((double)input[2]*input[2]);
    }
    
    stable_sort(robo,robo+N,
    [](const ROBOT& a,const ROBOT& b){
        return a.cost<b.cost;
    });
    
    for(int i=0;i<N;i++) cout << robo[i].no << '\n';
	return 0;
}