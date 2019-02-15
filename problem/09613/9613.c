#include <stdio.h>
 
int gcd(int a, int b) {
	if (b != 0)
		return gcd(b, a%b);
	else
		return a;
}
 
int main(void) {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		int numberArr[100];
		long long answer = 0;
 
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
			scanf("%d", numberArr + j);
 
		for (int j = 0; j < n - 1; j++)
			for (int k = j + 1; k < n; k++)
				answer += gcd(numberArr[j], numberArr[k]);
 
		printf("%lld\n", answer);
	}
	return 0;
}