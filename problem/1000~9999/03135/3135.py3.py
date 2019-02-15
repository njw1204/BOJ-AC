a,b=map(int,input().split());t=abs(a-b)
for i in range(int(input())):t=min(t,abs(int(input())-b)+1)
print(t)