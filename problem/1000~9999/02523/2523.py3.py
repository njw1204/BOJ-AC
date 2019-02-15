N=int(input())
for i in range(1,N*2): print('*'*(i if i<=N else N*2-i))