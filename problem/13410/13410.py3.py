n,k=map(int,input().split())
result=[0]*(k)
for i in range(k): result[i]=int(str(n*(i+1))[::-1])
print(max(result))