def f(n,i): print('*'*i+' '*(n*2-i*2)+'*'*i)
n=int(input())
for i in range(1,n+1): f(n,i)
for i in range(n-1,0,-1): f(n,i)