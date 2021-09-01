hiprime=[2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239]

x=[]
for i in range(30):
    nn=[1]
    for j in range(1999):
        nn.append(nn[-1]+hiprime[i])
    x.append(nn)

k,n=map(int,input().split())
for i in range(k):
    for j in range(n):
        print(x[i][j], end=' ')
    print()