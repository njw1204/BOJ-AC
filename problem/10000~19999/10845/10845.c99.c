#pragma warning(disable:4996)
#include <stdio.h>
#define MAX 10000

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x)
{
		rear = rear + 1;
		queue[rear] = x;
}

int dequeue()
{
		if(front>rear) {
			return -1;
		}
		else {
			int tmp = queue[front];
			front++;
			return tmp;
		}
}

int main()
{
	int times, i, num, result;
	char order[15];
	scanf("%d", &times);
	while (times>0) {
		scanf("%s", order);
		if (strcmp(order, "push") == 0) {
			scanf("%d", &num);
			enqueue(num);
		}
		else if (strcmp(order, "pop") == 0) {
			result = dequeue();
			printf("%d\n", result);
		}
		else if (strcmp(order, "size") == 0) {
			if(front>rear) printf("0\n");
			else printf("%d\n", rear - front + 1);
		}
		else if (strcmp(order, "empty") == 0) {
			if (front>rear) printf("1\n");
			else printf("0\n");
		}
		else if (strcmp(order, "front") == 0) {
			if (front>rear) puts("-1");
			else printf("%d\n", queue[front]);
		}
		else if (strcmp(order, "back") == 0) {
			if (front>rear) puts("-1");
			else printf("%d\n", queue[rear]);
		}
		times--;
	}
	return 0;
}