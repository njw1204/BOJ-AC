#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int (i)=0;(i)<int(n);(i)++)
#define ALL(list) (list).begin(),(list).end()
#define INPUT(cin_a) cin>>(cin_a)
#define DINPUT(int_a) int (int_a);INPUT(int_a)

int main() {
    vector<int> arr, lis;

    DINPUT(N);
    REP(i, N) {
        DINPUT(x);
        arr.push_back(x);
    }

    for (int i : arr) {
        auto p = lower_bound(ALL(lis), i);
        if (p == lis.end()) {
            lis.push_back(i);
        }
        else {
            *p = i;
        }
    }

    cout << N - lis.size();
}