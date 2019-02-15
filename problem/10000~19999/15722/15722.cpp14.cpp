#include <iostream>
using namespace std;

const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;
int N;
int dir = 0;
int x = 0, y = 0;
int level = 1;

bool move(){
  for (int i = 0; i < level; i++){
    if (N == 0) return true;
    if (dir == UP) y++;
    if (dir == RIGHT) x++;
    if (dir == DOWN) y--;
    if (dir == LEFT) x--;
    N--;
  }
  return false;
}

int main() {
  cin >> N;
  while(1) {
    if (move()) break;
    dir = (dir + 1) % 4;
    if (move()) break;
    dir = (dir + 1) % 4;
    level++;
  }
  cout << x << ' ' << y;
}