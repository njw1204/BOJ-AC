def CheckRange(n): return (n>=0 and n<=20)

def GetExpCount(index,value):
 if index==0: dp[0][arr[0]]=1
 else:
  for i in range(21):
   if CheckRange(i+arr[index]):
    dp[index][i+arr[index]]+=dp[index-1][i] if i>0 else GetExpCount(index-1,i)
   if CheckRange(i-arr[index]):
    dp[index][i-arr[index]]+=dp[index-1][i]
 return dp[index][value]

N = int(input())
arr = [*map(int,input().split())]
dp = [[0]*21 for i in range(N-1)]
goal = arr.pop()
print(GetExpCount(N-2,goal))