def ans(n):
 global fib
 for i in range(1,99):
  if fib[i]==n: return n
  if fib[i+1]>n: return ans(n-fib[i])

fib=[1]*100
for i in range(2,100):
 fib[i]=fib[i-1]+fib[i-2]
n=int(input())
print(ans(n))