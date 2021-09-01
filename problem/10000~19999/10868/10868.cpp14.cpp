#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int (i)=0;(i)<int(n);(i)++)
#define INPUT(cin_a) cin>>(cin_a)
#define INPUT2(cin_a,cin_b) cin>>(cin_a)>>(cin_b)
#define DINPUT(int_a) int (int_a);INPUT(int_a)
#define DINPUT2(int_a,int_b) int (int_a),(int_b);INPUT2(int_a,int_b)
#define PRINT(cout_x) cout<<(cout_x)<<'\n'
#define UNSYNC ios_base::sync_with_stdio(false); cin.tie(nullptr)

int N, M;
int bucket;
int arr[100005];
int sqrtMin[500];

int main() {
    UNSYNC;

    INPUT2(N, M);
    bucket = (int)sqrt(N);
    for (int i = 0; i < N; i++) {
        INPUT(arr[i]);
    }

    for (int& i : sqrtMin) {
        i = INT_MAX;
    }

    for (int i = 0, cnt = 0; i <= N; i += bucket, cnt++) {
        for (int j = i; j < i + bucket && j <= N; j++) {
            sqrtMin[cnt] = min(sqrtMin[cnt], arr[j]);
        }
    }

    REP(_, M) {
        DINPUT2(a, b);
        a--; b--;

        int aIdx = a / bucket, bIdx = b / bucket;
        int ans = INT_MAX;

        for (int i = aIdx + 1; i <= bIdx - 1; i++) {
            ans = min(ans, sqrtMin[i]);
        }

        if (aIdx == bIdx) {
            for (int i = a; i <= b; i++) {
                ans = min(ans, arr[i]);
            }
        }
        else {
            for (int i = a; i < (aIdx + 1) * bucket; i++) {
                ans = min(ans, arr[i]);
            }
            for (int i = bIdx * bucket; i <= b; i++) {
                ans = min(ans, arr[i]);
            }
        }

        PRINT(ans);
    }

    return 0;
}