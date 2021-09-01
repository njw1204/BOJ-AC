a,b,A,B,l=list(map(int, input().split())), list(map(int, input().split())),0,0,0
for i in range(10): (A,B,l) = (A+3,B,1) if a[i]>b[i] else (A,B+3,2) if a[i]<b[i] else (A+1,B+1,l)
print('{} {}\n{}'.format(A,B, 'A' if A>B or (A==B and l==1) else 'B' if A<B or (A==B and l==2) else 'D'))