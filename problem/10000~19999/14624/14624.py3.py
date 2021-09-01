n=int(input())
if n%2==0:
    print("I LOVE CBNU")
    exit(0)
print("*"*n)
for i in range(n//2+1):
    print(end=" "*(n//2-i))
    if i==0: print("*")
    else: print("*"+" "*(i*2-1)+"*")