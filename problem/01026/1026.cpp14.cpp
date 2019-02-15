#include <iostream>

int main(){
  int N;
  scanf("%d",&N);
  int* A = new int[N];
  int* B = new int[N];
  for(int i=0;i<N;i++){
    scanf("%d", A+i);
  }
  for(int i=0;i<N;i++){
    scanf("%d", B+i);
  }
  for(int i=0;i<N;i++){
    int A_min_index=i;
    int B_max_index=i;
    for(int j=i+1;j<N;j++){
      if(A[j]<A[A_min_index]) A_min_index=j;
      if(B[j]>B[B_max_index]) B_max_index=j;
    }
    if(A_min_index != i){
      int temp=A[i];
      A[i]=A[A_min_index];
      A[A_min_index]=temp;
    }
    if(B_max_index != i){
      int temp=B[i];
      B[i]=B[B_max_index];
      B[B_max_index]=temp;
    }
  }
  int result=0;
  for(int i=0;i<N;i++){
    result += A[i]*B[i];
  }
  printf("%d",result);
  delete[] A;
  delete[] B;
  return 0;
}