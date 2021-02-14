import math
a,b,c = map(int,input().split())
a = math.sqrt(a)
b = math.sqrt(b)
c = math.sqrt(c)
if a + b < c:
    print("Yes")
else:
    print("No")
