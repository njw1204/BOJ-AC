A,B=100,100
for _ in range(int(input())):
 AA,BB=map(int,input().split())
 if AA==BB: continue
 if AA>BB: B-=AA
 else: A-=BB
print(A)
print(B)