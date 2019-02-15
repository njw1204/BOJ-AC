#include <stdio.h>
#define MAX 50

char stack[MAX];
int top;
int underflow = 0;

void push(int x)
{
	top++;
	stack[top] = x;
}

void pop()
{
	if(top == -1)
		underflow = 1;
	else
		top = top - 1;
}

int main()
{
    char x[50];
	int times, i;
	scanf("%d", &times);
    getchar();
	while(times>0) {
		gets(x);
		i=0;
		top = -1;
        underflow = 0;
		while(x[i]) {
			if(x[i]=='(') push(x[i]);
			else if(x[i]==')') {
				pop();
				if(underflow==1) {
					top--;
					break;
				}
			}
			i++;
		}
		if(top==-1) printf("YES\n");
		else printf("NO\n");
		times--;
	}
	return 0;
}