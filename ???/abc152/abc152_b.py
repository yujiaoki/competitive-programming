a,b = map(int,input().split())
s1 = ""
s2 = ""
for i in range(b):
    s1+=str(a)
for i in range(a):
    s2+=str(b) 
if a >= b:
    print(s2)
else:
    print(s1)