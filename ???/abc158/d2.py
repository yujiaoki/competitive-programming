s = input()
q = int(input())
for i in range(q):
    t,s,c = input().split()
    if t == 1:
        swap(s[0],s[len(s)-1])
    else:
        f = int(input())
        c = input()
        if f == 1:
            s = c + s
        else :
            s = s + c
print(s)