import sys
input = sys.stdin.readline

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    n,m = MI()
    ans = pow(10,n) // m
    ans %= m
    print(ans)
            

main()
