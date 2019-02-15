fib=[0]*10001
fib[1]=1
for i in range(2,10001): fib[i]=fib[i-1]+fib[i-2]
print(fib[int(input())])