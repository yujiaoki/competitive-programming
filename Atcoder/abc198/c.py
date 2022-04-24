import sys
input = sys.stdin.readline
import math

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    r,x,y = map(int, input().split())
    # dis = math.sqrt(x**2 + y**2)
    # res = math.ceil(dis/r)
    dis = x**2 + y**2
    res = dis/(r**2)
    res = math.ceil(math.sqrt(res))
    print(res)

            

main()
