#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <time.h>
#include <memory.h>
#include <functional>

using namespace std;

typedef long long ll;

queue<int> q;
vector<int> v(1000001);

int BFS(int n) {
	int pointer = 0;
	q.push(n);
	v[n] = 1;
	while (true) {
		int now = q.front();
		q.pop();

		if (now == 1) return v[1] - 1;
		if (now % 3 == 0 && !v[now / 3]) {
			q.push(now / 3);
			v[now / 3] = v[now] + 1;
		}
		if (now % 2 == 0 && !v[now / 2]) {
			q.push(now / 2);
			v[now / 2] = v[now] + 1;
		}
		if (!v[now - 1]) {
			q.push(now - 1);
			v[now - 1] = v[now] + 1;
		}
	}
}

int main() {
	int n, cnt = 0;
	cin >> n;
	cout << BFS(n);

	return  0;
}