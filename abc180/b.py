import math
n = int(input())
x =  list(map(int,input().split()))
ans = 0
for i in range(n):
    ans += abs(x[i])
print(ans)
ans = 0
for i in range(n):
    ans += x[i]*x[i]
print(math.sqrt(ans))
ans = 0
for i in range(n):
    ans = max(ans,abs(x[i]))
print(ans)
