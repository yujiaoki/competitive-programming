import sys
input = sys.stdin.readline

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    a,b = map(int, input().split())
    for c in range(256):
        if a ^ c == b:
            print(c)
            return

            

main()
