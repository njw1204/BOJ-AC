MIN=lambda a,b: a if a<b else b

def FactoPowerCount(n,x):
 count = 0
 while n//x>0:
  count+=n//x
  n//=x
 return count

n,m=map(int,input().split())
print(MIN(FactoPowerCount(n,2)-FactoPowerCount(m,2)-FactoPowerCount(n-m,2),
          FactoPowerCount(n,5)-FactoPowerCount(m,5)-FactoPowerCount(n-m,5)))