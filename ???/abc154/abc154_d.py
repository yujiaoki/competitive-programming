n,k = map(int,input().split())
p = list(map(int,input().split()))
res = 0
for m in range(0,n-k+1):
    sum1 = 0
    for i in range(m,m+k):
        sum2 = sum(range(1,p[i]+1))
        sum1 += sum2/p[i]
    res = max(res,sum1)
print(res)
        