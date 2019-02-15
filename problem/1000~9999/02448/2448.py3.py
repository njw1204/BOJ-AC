import sys

def PrintTriangle(w,h,c,y):
 if w==5:
  result[y-2][c]='*'
  result[y-1][c-1]='*'
  result[y-1][c+1]='*'
  for i in range(c-2,c+3): result[y][i]='*'
  return
 PrintTriangle(w//2,h//2,c,y-h//2)
 PrintTriangle(w//2,h//2,c-(w//4+1),y)
 PrintTriangle(w//2,h//2,c+(w//4+1),y)

def PrintResult(N):
 for i in range(N): sys.stdout.write(''.join(result[i])+'\n')

N=int(input())
result=[[' ']*(N*2) for j in range(N)]
PrintTriangle(N*2-1,N,N-1,N-1)
PrintResult(N)