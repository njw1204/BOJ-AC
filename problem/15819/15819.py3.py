n,c=map(int,input().split())
x=[]
for i in range(n): x.append(input())
x.sort()
print(x[c-1])