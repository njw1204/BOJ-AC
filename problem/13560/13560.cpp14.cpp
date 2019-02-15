#include <cstdio>
#include <algorithm>
#define MAX_N 10000
using namespace std;
int c[MAX_N + 1], n, f;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    sort(c + 1, c + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (c[i] > n - i || c[i] < 0) {
            f = 1;
            break;
        }
        for (int j = 0; j < n - c[i] - i; j++)
            c[n - j]--;
        sort(c + i + 1, c + 1 + n);
    }
    printf("%d\n", f ? -1 : 1);
    return 0;
}