arr=[]
for i in range(9):
 for j in map(int,input().split()): arr.append(j)
M=max(arr)
print(M)
print(arr.index(M)//9+1,arr.index(M)%9+1)