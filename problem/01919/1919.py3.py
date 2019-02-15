T=[[0]*26 for _ in range(2)]
for i in range(2):
 for j in input(): T[i][ord(j)-ord('a')]+=1
ans=0
for i in range(26):
 if T[0][i]!=T[1][i]: ans+=abs(T[0][i]-T[1][i])
print(ans)