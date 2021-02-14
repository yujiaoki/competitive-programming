
n = int(input())
ans = 0
for i in range(n+1):
    l = n - i
    c = 1-4*(2*n-l*l-l)
    if c < 0:
        break
    if (1+math.sqrt(c))/2 <= l and (1+sqrt(c))/2 == (1+sqrt(c))//2:
        ans+=1
    if (1-math.sqrt(c))/2 <= l and (1-sqrt(c))/2 == (1-sqrt(c))//2:
        ans+=1
print(ans)
