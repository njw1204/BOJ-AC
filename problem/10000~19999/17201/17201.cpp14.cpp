#include <stdio.h>

int main() {
	int n, i;
	scanf("%d%d", &n, &i);
    if (i == 121212 || i == 212121
        || i == 12121212 || i == 21212121
        || i == 1212121212 || i == 2121212121)
        printf("Yes");
    else
        printf("No");
	return 0;
}