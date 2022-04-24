import sys
input = sys.stdin.readline

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

x = input()
m = int(input())
k = sorted(x)
ma = int (k[len(k)-1])
count = 0
num = ma + 1
while True:
    now = 0
    res = True
    for i in reversed(range(0,len(x)-1)):
        now += int(x[i])*num**i
        if now > m:
            res = False
            break
    if now > m:
        res = False
    if res == True:
        count += 1
        num += 1
    else :
        break

print(count)