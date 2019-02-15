#include <iostream>
#include <cstring>
#define N 1000001
using namespace std;

int main()
{
	cin.tie(NULL);

	int cnt = 1, nullidx = 0;
	char* arr = new char[N];
	cin.getline(arr, N);
	nullidx = strlen(arr);

	for (int i = 1; i < nullidx; i++)
	{
		if (arr[i] == ' ' && arr[i - 1] != ' ')
			cnt++;
	}
	if (arr[nullidx - 1] == ' ') cnt--;

	if (nullidx == 0) cnt = 0; //NULL만 있음

	cout << cnt << endl;

	delete[] arr;
	return 0;
}