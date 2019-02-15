#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;
  cin.ignore(1024,'\n');
  string* userArr = new string[N];
  
  for(int i=0;i<N;i++){
    getline(cin,userArr[i]);
  }

  stable_sort(userArr,userArr+N,
    [](const string& A, const string& B)->bool{
      int cut_A=0, cut_B=0;
      while(A[cut_A]!=' ') cut_A++;
      while(B[cut_B]!=' ') cut_B++;
      return (stoi(A.substr(0,cut_A)) < stoi(B.substr(0,cut_B)));
    }
  );

  for(int i=0;i<N;i++){
    cout << userArr[i] << '\n';
  }

  delete[] userArr;
  return 0;
}