import sys
input = sys.stdin.readline
import math


x,k,d = map(int, input().split())

x = abs(x)
if x < k * d:
    k -= x//d
    x %= d
    if k % 2 == 0:
        print(x)
    else:
        print(d-x)

else :
    print(x - k*d)