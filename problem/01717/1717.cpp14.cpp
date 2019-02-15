#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int parent[1000005];

int Find(int x) {
  if (parent[x] != -1) return parent[x] = Find(parent[x]);
  else return x;
}

void Union(int a, int b) {
  int ppa = Find(a), ppb = Find(b);
  if (ppa == ppb) return;
  parent[ppb] = ppa;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> M;
  memset(parent, -1, sizeof(parent));
  
  for (int i = 0; i < M; i++) {
    int op, a, b;
    cin >> op >> a >> b;
    
    if (op == 0) Union(a, b);
    else {
      if (Find(a) == Find(b)) cout << "YES" << '\n';
      else cout << "NO" << '\n';
    }
  }
  
  return 0;
}