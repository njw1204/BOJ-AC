L=[0]*42
for _ in range(10): L[int(input())%42]=1
print(sum(L))