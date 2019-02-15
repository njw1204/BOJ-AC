#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <climits>
#define MAX(x,y) ((x)>(y)?(x):(y))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

ll node[5000005], dp[5000005];
ll k;
map<int, int> nodeStart;

int main() {
	int cnt = 2;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < 1 << i; j++) {
			if (j == 0) nodeStart[i] = cnt;
			cin >> node[cnt];
			cnt++;
		}
	}

	for (int i = nodeStart[k]; i < cnt; i+=2) {
		node[i] = MAX(node[i], node[i + 1]);
		node[i + 1] = node[i];
		dp[i] = node[i];
		dp[i + 1] = node[i + 1];
	}

	for (int level = k - 1; level >= 1; level--) {
		for (int i = nodeStart[level]; i < nodeStart[level + 1]; i+=2) {
			ll left = dp[i * 2], right = dp[(i + 1) * 2];
			ll diff = left - right, nodeDiff = node[i] - node[i + 1];

			if (nodeDiff > -diff) {
				node[i + 1] += nodeDiff + diff;
			}
			else {
				node[i] += -diff - nodeDiff;
			}

			/*
			if (node[i] > node[i + 1]) {
				if (left >= right) node[i + 1] = node[i] + (left - right);
				else {
					if (node[i] < node[i + 1] + (right - left))
						node[i + 1] = node[i] - (right - left);
					else
						node[i] = node[i + 1] + (right - left);
				}
			}
			else {
				if (right >= left) node[i] = node[i + 1] + (right - left);
				else {
					if (node[i + 1] < node[1] + (left - right))
						node[i] = node[i + 1] - (left - right);
					else
						node[i + 1] = node[i] + (left - right);
				}
			}
			/*if (node[i + 1] - node[i] > diff) {
				node[i] = node[i + 1] - diff;
			}
			else {
				node[i] = node[i + 1] - diff;
			}

			if (nodeDiff > -diff) {
				node[i + 1] = node[i] + diff;
			}*/
			dp[i] = node[i] + left;
			dp[i + 1] = node[i + 1] + right;
		}
	}

	ll ans = 0;
	for (ll x : node) {
		ans += x;
	}

	cout << ans;
	return 0;
}