#include <stdio.h>
int main(void) {
    int n;
    scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++) putchar('*');
		puts("");
	}
	return 0;
}