import sys
import math
input = sys.stdin.readline

n = int(input())
ans = 0
for k in range(1,n+1):
    if k*k > n:
        break
    a = 2*n/k-k+1
    if a > 0 and a % 2 == 0:
        ans+=2
print(ans)

