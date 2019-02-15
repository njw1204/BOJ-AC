#include <iostream> 
using namespace std; 
int main() { 
   int n,x; 
   cin >> n >> x; 
   if(n < 1 || x > 10000) 
   return 0; 
   int *a = new int[n]; 
   int score[10000]; 
   int count = 0; 
   for(int i = 0; i<n; i++){ 
      cin >> a[i]; 
   } 
   for(int i = 0; i<n; i++){ 
      if(a[i] < x){ 
         score[count] = a[i]; 
         count++; 
      } 
   } 
   for(int i = 0; i<count; i++){ 
      cout << score[i] << " "; 
   } 
   delete[] a; 
} 