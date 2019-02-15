#include <iostream>
using namespace std;

int resident[15][15] = {};

int GetResident(int k, int n){
  int result = 0;

  for (int i=1;i<=n;i++){
    if (resident[k-1][i]==0) result += GetResident(k-1,i);
    else result += resident[k-1][i];
  }

  resident[k][n] = result;
  return result;
}

int main() {
  int T;
  cin >> T;

  for(int i=0;i<15;i++) resident[0][i] = i;

  for(int i=0;i<T;i++){
    int K, N;
    cin >> K >> N;
    cout << GetResident(K,N) << '\n';
  }

  return 0;
}