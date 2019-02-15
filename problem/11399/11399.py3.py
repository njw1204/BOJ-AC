N=int(input())
L=[*map(int,input().split())]
L.sort()
ans=0
for i in range(N): ans+=(N-i)*L[i]
print(ans)