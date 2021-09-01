#include <cstdio>

int arr[1000000];
int cp[1000000];

void MergeSort(int* ptr, int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    MergeSort(ptr, start, mid);
    MergeSort(ptr, mid + 1, end);

    int i, a, b;
    for (i = 0, a = start, b = mid + 1; a <= mid && b <= end; i++) {
      if (ptr[a] <= ptr[b])
        cp[i] = ptr[a++];
      else
        cp[i] = ptr[b++];
    }
      
    while (a <= mid) cp[i++] = ptr[a++];
    while (b <= end) cp[i++] = ptr[b++];

    for (int i = start; i <= end; i++)
      arr[i] = cp[i - start];
  }
}

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", arr + i);
  MergeSort(arr, 0, N - 1);
  for (int i = 0; i < N; i++) printf("%d\n", arr[i]);
  return 0;
}