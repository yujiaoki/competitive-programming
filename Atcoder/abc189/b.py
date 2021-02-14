import sys
input = sys.stdin.readline

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    
    n,x = map(int, input().split())
    su = 0
    res = False
    for i in range(n):
        v,p = map(int, input().split())
        su += v*p/100
        if su > x:
            print(i+1)
            res = True
            break
    if res == False:
        print(-1)

            

main()
