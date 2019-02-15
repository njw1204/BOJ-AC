#include <iostream>
#define NOTHING 0xC0000000
using namespace std;

int w[21][21][21];

int Calc(int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0) return 1;
  if (a > 20 || b > 20 || c > 20) return Calc(20,20,20);
  if (w[a][b][c] != NOTHING) return w[a][b][c];
  
  if (a < b && b < c)
    w[a][b][c]=Calc(a,b,c-1)+Calc(a,b-1,c-1)-Calc(a,b-1,c);
  else
    w[a][b][c]=Calc(a-1,b,c)+Calc(a-1,b-1,c)
               +Calc(a-1,b,c-1)-Calc(a-1,b-1,c-1);

  return w[a][b][c];
}

int main() {
  for(int i=0;i<21;i++){
    for(int j=0;j<21;j++){
      for(int k=0;k<21;k++)
        w[i][j][k] = NOTHING;
    }
  }

  while(1){
    int a,b,c;
    cin >> a >> b >> c;
    if(a==-1 && b==-1 && c==-1) break;
    cout << "w(" << a << ", "
         << b << ", " << c
         << ") = " << Calc(a,b,c) << '\n';
  }

  return 0;
}