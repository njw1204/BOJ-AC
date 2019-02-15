n=int(input())
x=set()
for i in map(int,input().split()): x.add(i)
for i in range(1,n+1):
 if i not in x: print(i)