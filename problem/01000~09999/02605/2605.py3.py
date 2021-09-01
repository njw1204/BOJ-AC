arr=[];input()
for n,i in enumerate(map(int,input().split())):arr.insert(n-i,n+1)
print(' '.join(map(str,arr)))