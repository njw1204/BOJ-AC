n=int(input())
for i in range(1,n+1):
 if i<2:print(' '*(n-1)+'*')
 elif i<n:print(' '*(n-i)+'*'+' '*(i*2-3)+'*')
 else:print('*'*(n*2-1))