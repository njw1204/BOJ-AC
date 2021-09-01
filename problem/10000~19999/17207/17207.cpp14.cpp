#include <bits/stdc++.h>
using namespace std;
#define sci(n) scanf("%lld", &(n))
#define scd(n) scanf("%Ld", &(n))
typedef long long ll;
typedef long double ld;
typedef vector< vector<ll> > matrix;
matrix operator* (const matrix &a, const matrix &b) {
	int n = a.size(), m = a[0].size(), l = b[0].size();
	matrix c(n, vector<long long>(l));
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<l; j++) {
			for (int k = 0; k<m; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}

int main(void)
{
	matrix a(5, vector<ll>(5)), b(5, vector<ll>(5)), c(5, vector<ll>(5));
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			sci(a[i][j]);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			sci(b[i][j]);

	c = a*b;

	vector<ll> sum;
	for (int i = 0; i < 5; i++) {
		ll s = 0;
		for (int j = 0; j < c[i].size(); j++) {
			s += c[i][j];
		}
		sum.push_back(s);
	}
	ll mn = 1e9, mn_idx = -1;
	vector<string> as={"Inseo", "Junsuk", "Jungwoo", "Jinwoo", "Youngki" };
	for (int i = 0; i < sum.size(); i++) {
		if (sum[i] <= mn) {
			mn = sum[i];
			mn_idx = i;
		}
	}
	cout << as[mn_idx];
	return 0;
}