#include <stdio.h>

int queue[25000000];
int front = 0, rear = -1;

void enqueue(int x)
{
	rear = rear + 1;
	queue[rear] = x;
}

int dequeue()
{
	int tmp = queue[front];
	front++;
	return tmp;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	printf("<");
	int i, c=0;
	for(i=0;i<N;i++) {
		enqueue(i+1);
	}
	while(c<N) {
		for(i=0;i<M-1;i++) {
			enqueue(dequeue());
		}
		if(c<N-1) printf("%d, ", dequeue());
		else printf("%d", dequeue());
		c++;
	}
	printf(">");
	return 0;
}