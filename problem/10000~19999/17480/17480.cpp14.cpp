#include <iostream>

#include <string>

#include <set>

#include <vector>

#include <algorithm>

using namespace std;

string wo;

int alphaCnt[500];

set<string> result;

void solve(vector<char> str, int i, int j) {

	int strSize = j - i + 1;

	if (strSize <= 2) {

		string x;

		for (char t : str) {

			x.push_back(t);

		}

		result.insert(x);

		return;

	}

	

	if (strSize % 2 == 0) {

		int mid = (i + j) / 2;

		vector<char> tempStr = str;

		

		reverse(str.begin() + i, str.begin() + mid + 1);

		solve(str, mid + 1, j);

		

		str = tempStr;

		reverse(str.begin() + mid + 1, str.begin() + j + 1);

		solve(str, i, mid);

	}

	else {

		int mid = (i + j) / 2;

		vector<char> tempStr = str;

		reverse(str.begin() + i, str.begin() + mid + 1);

		solve(str, mid + 1, j);

		str = tempStr;

		reverse(str.begin() + mid + 1, str.begin() + j + 1);

		solve(str, i, mid);

		mid--;

		str = tempStr;

		reverse(str.begin() + i, str.begin() + mid + 1);

		solve(str, mid + 1, j);

		str = tempStr;

		reverse(str.begin() + mid + 1, str.begin() + j + 1);

		solve(str, i, mid);

	}

}

int main() {

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {

		string x;

		cin >> x;

		int c;

		cin >> c;

		alphaCnt[x[0]] += c;

	}

	cin >> wo;

	for (int i = 0; i < wo.size(); i++) {

		for (int j = 1; j <= wo.size() - i; j++) {

			string c;

			c = wo.substr(i, j);

			int tempAlpha[200] = { 0 };

			for (int k = 0; k < c.size(); k++) {

				tempAlpha[c[k]]++;

			}

			bool fail = false;

			for (int k = 0; k < 200; k++) {

				if (alphaCnt[k] != tempAlpha[k]) {

					fail = true;

					break;

				}

			}

			vector<char> vec;

			if (!fail) {

				// cout << c << '\n';

				for (char xcc : c) {

					vec.push_back(xcc);

				}

				solve(vec, 0, vec.size() - 1);

			}

		}

	}

	cout << result.size() << '\n';

}