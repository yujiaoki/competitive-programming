import sys
input = sys.stdin.readline

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))
def LLI(): return [int(input()) for i in range(n)]
n,a,b = map(int, input().split())
s = []
for i in range(n):
    ss = int(input())
    s.append(ss)

ma = max(s)
mi = min(s)
if ma == mi:
    print(-1)
else :
    p = b/(ma-mi)
    su = sum(s)
    q = a - p*su/n
    print(p,q)