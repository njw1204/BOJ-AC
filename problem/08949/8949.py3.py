A,B=input().split()
if len(A)>len(B): B='0'*(len(A)-len(B))+B
else: A='0'*(len(B)-len(A))+A
for i in range(len(A)): print(int(A[i])+int(B[i]),end='')