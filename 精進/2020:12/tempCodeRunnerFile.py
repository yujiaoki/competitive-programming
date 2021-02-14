import sys
input = sys.stdin.readline



x,k,d = map(int, input().split())

x = abs(x)
if x < k * d:
    k -= x/d
    x -= x//d*d
    if k % 2 == 0:
        print(x)
    else:
        print(d-x)

else :
    print(x - k*d)