import sys
input = sys.stdin.readline

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

n,k,m,r = map(int, input().split())
s = []
for i in range(n-1):
    crt = int(input())
    s.append(crt)
s.sort(reverse=True)
# print(s)
su = 0
for i in range(k):
    su += s[i]
if su >= k*r :
    print(0)
else :
    ans = k*r
    for i in range(k-1):
        ans -= s[i]
    # print(ans)
    if ans <= m: 
        print(ans)
    else :
        print(-1)        

