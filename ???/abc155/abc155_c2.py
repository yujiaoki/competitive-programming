
n = int(input())
m = []
for _ in range(n):
    x = input()
    m.append(x)
s=sorted(m)
max_n = 1
res = 0
for i in range(n-1):
    if  s[i] ==s[i+1]:
        max_n+=1
    else :
        res = max(max_n,res)
        max_n = 1
count =1
for i in range(n-1):
    if s[i] == s[i+1]:
        count+=1
    else:
        if count == res:
            print(s[i])
            count =1

