score,ans=[],0
N=int(input())
for _ in range(N): score.append(int(input()))
score.reverse()
for i in range(1,N):
  if score[i]>=score[i-1]:
    ans+=score[i]-score[i-1]+1
    score[i]=score[i-1]-1
print(ans)