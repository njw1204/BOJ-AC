#include <stdio.h>

int main(){
  int N;
  scanf("%d", &N);

  for (int i = 0; i < N * 2 - 1; i++){
	int star = N * 2 - 1 - (i * 2);
	if (star < 0) star = 2 - star;
	int blank = (N * 2 - 1 - star) / 2;

	for (int j = 0; j < blank; j++) putchar(' ');
	for (int j = 0; j < star; j++) putchar('*');
	puts("");
  }
  return 0;
}