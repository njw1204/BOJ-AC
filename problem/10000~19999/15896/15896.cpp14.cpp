#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int N;
vector<int> A, B;

int Solve1() {
    int bitcnt[30] = {}, bitsum[30] = {};

    for (int i : A) {
        for (int j = 0; j < 30; j++) {
            int base = 1 << j;
            if (i & base)
                bitcnt[j]++;
        }
    }

    for (int i : B) {
        for (int j = 0; j < 30; j++) {
            int base = 1 << j;
            if (i & base)
                bitsum[j] = (bitsum[j] + bitcnt[j]) % 1999;
        }
    }

    int ans = 0;
    for (int i = 0; i < 30; i++) {
        ans += (1LL << i) % 1999 * bitsum[i] % 1999;
        ans %= 1999;
    }
    return ans;
}

int Solve2() {
    int minA[30][2] = {}, minB[30][2] = {};
    int maxA[30][2] = {}, maxB[30][2] = {};

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 2; j++) {
            minA[i][j] = INT_MAX;
            maxA[i][j] = INT_MIN;
            minB[i][j] = INT_MAX;
            maxB[i][j] = INT_MIN;
        }
    }

    int mask = 1, firstBit = 1;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < N; j++) {
            int aFirst = 0, bFirst = 0;
            if (A[j] & firstBit) aFirst = 1;
            if (B[j] & firstBit) bFirst = 1;

            minA[i][aFirst] = min(minA[i][aFirst], A[j] & mask);
            maxA[i][aFirst] = max(maxA[i][aFirst], A[j] & mask);
            minB[i][bFirst] = min(minB[i][bFirst], B[j] & mask);
            maxB[i][bFirst] = max(maxB[i][bFirst], B[j] & mask);
        }
        
        mask = (mask << 1) + 1;
        firstBit <<= 1;
    }

    char result[30] = {};
    memset(result, 1, sizeof(result));
    firstBit = 1;

    for (int i = 0; i < 30; i++) {
        if (minA[i][0] != INT_MAX && minB[i][0] != INT_MAX &&
            ((minA[i][0] + minB[i][0]) & firstBit) == 0)
            result[i] = 0;

        if (maxA[i][1] != INT_MIN && maxB[i][0] != INT_MIN &&
            ((maxA[i][1] + maxB[i][0]) & firstBit) == 0)
            result[i] = 0;

        if (maxA[i][0] != INT_MIN && maxB[i][1] != INT_MIN &&
            ((maxA[i][0] + maxB[i][1]) & firstBit) == 0)
            result[i] = 0;

        if (minA[i][1] != INT_MAX && minB[i][1] != INT_MAX &&
            ((minA[i][1] + minB[i][1]) & firstBit) == 0)
            result[i] = 0;

        firstBit <<= 1;
    }

    int ans = 0, weight = 1;
    for (int i = 0; i < 30; i++) {
        if (result[i]) ans += weight;
        weight <<= 1;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        A.push_back(x);
    }
    for (int i = 0; i < N; i++) {
        cin >> x;
        B.push_back(x);
    }

    cout << Solve1() << ' ' << Solve2();
    return 0;
}