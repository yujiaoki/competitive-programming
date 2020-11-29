import sys
input = sys.stdin.readline
MOD = 998244353
def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    a,b,c = MI()
    ans = a
    ans%= MOD
    ans *= a+1
    ans/=2
    ans%= MOD
    ans = b
    ans%= MOD
    ans *= b+1
    ans/=2
    ans%= MOD
    ans = c
    ans%= MOD
    ans *= c+1
    ans/=2
    ans%= MOD
    print(ans)


            

main()
