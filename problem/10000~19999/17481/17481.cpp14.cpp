#include <iostream>

#include <string>

#include <map>

#include <vector>

#include <cstring>

using namespace std;

int n, m;

map<string, int> nameToId;

vector<int> likes[1005];

int visited[1005];

int b[1005];

int dfs(int here) {

	if (visited[here]) return 0;	visited[here] = 1;

	for (int i = 0; i < likes[here].size(); i++) {

		int there = likes[here][i];

		if (!b[there] || dfs(b[there])) {

			b[there] = here;

			return 1;

		}

	}

	return 0;

}

int bmatch() {

	int ret = 0;

	for (int i = 1; i <= n; i++) {

		memset(visited, 0, sizeof(visited));

		if (dfs(i)) ret++;

	}

	return ret;

}

int main() {

	cin >> n >> m;

	for (int i = 1; i <= m; i++) {

		string x;

		cin >> x;

		nameToId[x] = i;

	}

	for (int i = 1; i <= n; i++) {

		int x;

		cin >> x;

		for (int j = 0; j < x; j++) {

			string name;

			cin >> name;

			likes[i].push_back(nameToId[name]);

		}

	}

	int result = bmatch();

	if (result == n) {

		cout << "YES";

	}

	else {

		cout << "NO\n" << result;

	}

	return 0;

}