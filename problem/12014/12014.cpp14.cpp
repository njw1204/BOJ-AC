#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
  int T;
  cin >> T;
  for(int i=1;i<=T;i++){
  	cout << "Case #" << i << '\n';
  	vector<int> asdf, qwer;
  	int n,k;
  	cin >> n >> k;
  	for(int j=0;j<n;j++){
  	  int x;
  	  cin >> x;
  	  auto y = lower_bound(asdf.begin(),asdf.end(),x);
  	  if(y==asdf.end()) asdf.push_back(x);
  	  else *y = x;
  	}
  	if(asdf.size()>=k) cout << 1 << '\n';
  	else cout << 0 <<'\n';
  }
}