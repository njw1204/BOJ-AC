n=int(input())
t=[[' ']*n for _ in range(2)]
for i in range(n):t[i%2][i]='*'
ans=''.join(t[0])+'\n'+''.join(t[1])
exec('print(ans);'*n)