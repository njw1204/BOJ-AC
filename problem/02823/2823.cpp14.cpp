#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int R, C;
bool visit[15][15];
char field[15][15];

const int LEFT = 1, RIGHT = 2, DOWN = 3, UP = 4;

bool BruteForce(int ni, int nj, int si, int sj, int dir, bool first) {
  if (ni == si && si == sj && !first) return true;
  if (visit[ni][nj]) return true;
  visit[ni][nj] = true;

  bool check = true, isPath = false;
  if (dir != RIGHT && field[ni][nj - 1] == '.') {
    isPath = true;
    check &= BruteForce(ni, nj - 1, si, sj, LEFT, false);
  }
  if (dir != LEFT && field[ni][nj + 1] == '.') {
    isPath = true;
    check &= BruteForce(ni, nj + 1, si, sj, RIGHT, false);
  }
  if (dir != UP && field[ni + 1][nj] == '.') {
    isPath = true;
    check &= BruteForce(ni + 1, nj, si, sj, DOWN, false);
  }
  if (dir != DOWN && field[ni - 1][nj] == '.') {
    isPath = true;
    check &= BruteForce(ni - 1, nj, si, sj, UP, false);
  }

  return check & isPath;
}

int main() {
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      field[i][j] = 'X';
    }
  }

  cin >> R >> C;
  for (int i = 1; i <= R; i++) {
    getchar();
    for (int j = 1; j <= C; j++) {
      scanf("%c", &field[i][j]);
    }
  }

  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      if (field[i][j] == '.') {
        memset(visit, 0, sizeof(visit));
        if (BruteForce(i, j, i, j, 0, true) == false)
          return cout << 1, 0;
      }
    }
  }

  return cout << 0, 0;
}