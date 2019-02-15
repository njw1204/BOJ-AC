N,M=map(int,input().split())
arr=[i+1 for i in range(N)]
result=[0]*N
pos=0
for i in range(N):
 pos=(pos+M-1)%len(arr)
 result[i]=str(arr.pop(pos))
print('<'+', '.join(result)+'>')