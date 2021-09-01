#include <bits/stdc++.h>
using namespace std;

int numCnt[2][4001], sum, nMin = 9999, nMax = -9999, most_cnt = -1, most_val = INT_MAX, most_ord = 0;
vector<int> numList;

int main() {
    int N;
    scanf("%d", &N);
    numList.reserve(N);

    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        sum += num;
        nMin = nMin < num ? nMin : num;
        nMax = nMax > num ? nMax : num;
        most_cnt = max(most_cnt, ++numCnt[num < 0][abs(num)]);
    }

    for (int num = -4000; num <= 4000; num++) {
        if (numCnt[num < 0][abs(num)] == most_cnt && most_ord < 2) {
            most_val = num;
            most_ord++;
        }
        for (int i = 0; i < numCnt[num < 0][abs(num)]; i++) {
            numList.push_back(num);
        }
    }

    printf("%.0lf\n%d\n%d\n%d\n", sum / (double)N, numList[N / 2], most_val, nMax - nMin);
}