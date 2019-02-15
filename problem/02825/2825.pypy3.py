import sys

def to(n):
    ret = 0
    while n > 0:
        ret |= (1 << (n % 10))
        n //= 10
    return ret

input = sys.stdin.readline
cnt = [0 for i in range(1024)]
n = int(input())
for i in range(n):
    a = int(input())
    cnt[to(a)] += 1
ret = 0
for i in range(1024):
    ret += cnt[i] * (cnt[i] - 1) // 2
    for j in range(i + 1, 1024):
        if i & j:
            ret += cnt[i] * cnt[j]
print(ret)