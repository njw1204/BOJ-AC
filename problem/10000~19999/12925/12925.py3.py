def mat_mul(a, b):
    c = []
    for i in range(len(a)):
        c.append([0]*len(b[0]))
        for j in range(len(b[0])):
            for k in range(len(a[0])):
                c[i][j] += (a[i][k]*b[k][j])
                c[i][j] = (c[i][j] + 1000) % 1000
    return c

def mat_pow(a, n):
    if n<=0:
        return None
    if n==1:
        return a
    if n==2:
        return mat_mul(a, a)
    t1 = mat_pow(a, n//2)
    if n%2==0:
        return mat_mul(t1, t1)
    return mat_mul(t1, mat_mul(a, t1))

for t in range(1,int(input())+1):
 n=int(input())
 m=[[6,996],[1,0]]
 print(end="Case #%d: " % t)
 print("%03d" % (mat_mul(mat_pow(m,n),[[6],[2]])[1][0]-1))