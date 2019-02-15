#include <iostream>
#include <cstdio>
#define MAX(x,y) ((x)>(y)?(x):(y))
using namespace std;

struct Item {
  int val[4][4];
  char color[4][4];
};

int n;
Item item[10];

int solve(int a, int b, int c, int adir, int bdir, int cdir, int apos, int bpos, int cpos) {
  Item temp[3];

  for (int ii = 0; ii < 3; ii++) {
    int key, sel;
    if (ii == 0) {
      key = adir;
      sel = a;
    }
    else if (ii == 1) {
      key = bdir;
      sel = b;
    }
    else {
      key = cdir;
      sel = c;
    }

    switch (key) {
    case 0:
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          temp[ii].val[i][j] = item[sel].val[i][j];
          temp[ii].color[i][j] = item[sel].color[i][j];
        }
      }
      break;
    case 1:
      for (int i = 0; i < 4; i++) {
        for (int j = 3; j >= 0; j--) {
          temp[ii].val[i][3 - j] = item[sel].val[j][i];
          temp[ii].color[i][3 - j] = item[sel].color[j][i];
        }
      }
      break;
    case 2:
      for (int i = 3; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
          temp[ii].val[3 - i][3 - j] = item[sel].val[i][j];
          temp[ii].color[3 - i][3 - j] = item[sel].color[i][j];
        }
      }
      break;
    case 3:
      for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
          temp[ii].val[3 - i][j] = item[sel].val[j][i];
          temp[ii].color[3 - i][j] = item[sel].color[j][i];
        }
      }
      break;
    }
  }

  int nowVal[5][5] = {0};
  int nowColor[5][5] = {0};

  for (int ii = 0; ii < 3; ii++) {
    int key;
    if (ii == 0) {
      key = apos;
    }
    else if (ii == 1) {
      key = bpos;
    }
    else {
      key = cpos;
    }

    int mi = 0, mj = 0;
    switch (key) {
    case 1:
      mi = 1;
      break;
    case 2:
      mj = 1;
      break;
    case 3:
      mi = 1;
      mj = 1;
      break;
    }

    for (int i = mi; i < mi + 4; i++) {
      for (int j = mj; j < mj + 4; j++) {
        nowVal[i][j] += temp[ii].val[i - mi][j - mj];
        if (nowVal[i][j] < 0) nowVal[i][j] = 0;
        else if (nowVal[i][j] > 9) nowVal[i][j] = 9;
        switch (temp[ii].color[i - mi][j - mj]) {
        case 'R':
          nowColor[i][j] = 7;
          break;
        case 'B':
          nowColor[i][j] = 5;
          break;
        case 'G':
          nowColor[i][j] = 3;
          break;
        case 'Y':
          nowColor[i][j] = 2;
          break;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      ans += nowVal[i][j] * nowColor[i][j];
    }
  }

  return ans;
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        cin >> item[i].val[j][k];
      }
    }
    getchar();
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        scanf("%c ", &item[i].color[j][k]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (i == j || j == k || i == k) continue;
        for (int ii = 0; ii < 4; ii++) {
          for (int jj = 0; jj < 4; jj++) {
            for (int kk = 0; kk < 4; kk++) {
              for (int iii = 0; iii < 4; iii++) {
                for (int jjj = 0; jjj < 4; jjj++) {
                  for (int kkk = 0; kkk < 4; kkk++) {
                    ans = MAX(ans, solve(i, j, k, ii, jj, kk, iii, jjj, kkk));
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  return cout << ans, 0;
}