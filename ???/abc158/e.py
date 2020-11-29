n,p = map(int,input().split())
s = input()
count = 0
for i in range(n):
    for j in range(i,n):
        num = int(s[i:j+1])
        if num %p == 0 :
            count+=1

print(count)