def gcd(m,n): return m if n==0 else gcd(n,m%n)

for i in range(int(input())):
  maxGCD=1
  numList=list(map(int,input().split()))
  for j in range(len(numList)):
    for k in range(j+1,len(numList)):
      tempGCD = gcd(numList[j],numList[k])
      if tempGCD > maxGCD: maxGCD = tempGCD
  print(maxGCD)