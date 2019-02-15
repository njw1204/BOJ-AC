n=int(input())
x=[int(input()) for i in range(n)]
print(sum(x)/n)
x.sort()
print(x[n//2] if n%2 else (x[n//2-1]+x[n//2])/2)