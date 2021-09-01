A=int(input())
B=[*map(int,input())]
print(A*B[2],A*B[1],A*B[0],A*int(''.join(map(str,B))),sep='\n')