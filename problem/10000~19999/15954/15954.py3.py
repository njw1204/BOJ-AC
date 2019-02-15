import math
from decimal import Decimal, getcontext

getcontext().prec=30
n,k=map(int,input().split())
x=[*map(int,input().split())]
preSum=[0]*(n+5)
preSum[0]=x[0]
preExpSum=[0]*(n+5)
preExpSum[0]=x[0]**2
for i in range(1,n):
    preSum[i]=preSum[i-1]+x[i]
    preExpSum[i]=preExpSum[i-1]+(x[i]**2)

minStd=-1
for i in range(n-k+1):
    for j in range(i+k-1,n):
        cnt=Decimal(j-i+1)
        meanNow=Decimal((preSum[j]-preSum[i-1])/cnt)
        bunNow=Decimal((preExpSum[j]-preExpSum[i-1])-((meanNow*2)*(preSum[j]-preSum[i-1]))+((meanNow**2)*cnt))
        bunNow/=cnt
        if minStd==-1: minStd=bunNow
        else: minStd=min(minStd,bunNow)
print(minStd.sqrt())