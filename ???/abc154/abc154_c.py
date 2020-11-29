n = int(input())
b = [int(input()) for i in range(n)]
a = []
for i in b:
    a[i]+=1
if max(a) >= 2: 
    print("NO") 
else :
    print("YES") 