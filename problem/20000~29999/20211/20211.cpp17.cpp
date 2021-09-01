#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
#include <complex>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <bitset>
#include <limits>
#include <numeric>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
using namespace std;

int N;
string x;
vector<pair<int, int>> ans;
int dpsum[35000];
int dprevsum[35000];

int main() {
    cin >> N;
    cin >> x;

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            if (x[0] == 'H') {
                dpsum[0] = 3;
                dprevsum[0] = 3;
            }
            else {
                dpsum[0] = 5;
                dprevsum[0] = 1;
            }
        }
        else {
            if (x[i] == 'H') {
                dpsum[i] = dpsum[i - 1] + 3;
                dprevsum[i] = dprevsum[i - 1] + 3;
            }
            else {
                if (dpsum[i - 1] % 2) {
                    dpsum[i] = dpsum[i - 1] + 1;
                    dprevsum[i] = dprevsum[i - 1] + 5;
                }
                else {
                    dpsum[i] = dpsum[i - 1] + 5;
                    dprevsum[i] = dprevsum[i - 1] + 1;
                }
            }
        }
    }

    for (int expForLvUp = 1; expForLvUp <= N * 5; expForLvUp++) {
        bool isFail = true;
        int currentLv = 0;
        int prevRight = -1;

        while (prevRight < N - 1) {
            int left = prevRight + 1, right = N - 1;
            int* dpref = dpsum;

            if (prevRight != -1 && dpsum[prevRight] % 2 == 1) {
                dpref = dprevsum;
            }

            while (1) {
                int mid = (left + right) / 2;
                int currentExp = dpref[mid] - (prevRight != -1 ? dpref[prevRight] : 0);

                if (left == right) {
                    isFail = (currentExp < expForLvUp);
                    break;
                }
                else if (currentExp >= expForLvUp) {
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }

            prevRight = left;
            if (!isFail) {
                currentLv++;
            }
        }

        if (!isFail) {
            ans.push_back({ expForLvUp, currentLv });
        }
    }

    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i.first << ' ' << i.second << '\n';
    }

    return 0;
}