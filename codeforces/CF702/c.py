import sys
input = sys.stdin.readline
# import math

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

t = int(input())
while t > 0:
    t-=1
    x = int(input())
    if x == 1:
        print("No")
        continue
    res = False
    for a in range(1,100001):
        k = x - a*a*a
        if k <= 0:
            break
        b = float(k ** (1/3))
        if abs(b - round(b)) < 1e-8:
            res = True
            break
    if res == True:
        print("Yes")
    else: 
        print("No")
# k = 703657519796 - 5779*5779*5779
# b = float(k ** (1/3))
# print(b)
