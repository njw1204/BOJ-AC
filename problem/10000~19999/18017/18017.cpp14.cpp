#include <stdio.h>
int main() {
    long double a, b;
	long long c = 299792458L;
	scanf("%Lf%Lf",&a,&b);
    printf("%.15Lf",(a+b)/(1+a/c*b/c));
}