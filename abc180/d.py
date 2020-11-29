
X, Y, A, B = map(int,input().split())
x = X
ans = 0
while True:
    # if (Y/A < x) break;
    if A*x >= Y:
        break
    if A*x >= x + B:
        break
    ans+=1
    x*=A
ans += (Y-1-x)//B
print(ans)

