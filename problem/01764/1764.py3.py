import sys
(N,M),L,LL=map(int,input().split()),set(),set()
for _ in range(N): L.add(sys.stdin.readline())
for _ in range(M): LL.add(sys.stdin.readline())
ans=""
for i in sorted(L&LL): ans+=i
print(ans.count('\n'),ans,sep='\n')