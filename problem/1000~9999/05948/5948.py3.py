n=int(input())
a=0
al=dict()
while n not in al:
    al[n]=True
    n=(n//100%10*10+n//10%10)**2
print(len(al))